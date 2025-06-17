#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "lexer.h"
#include "parser.h"

// you can declare prototypes of parser functions below

// #include "lexer.c"
// #include <stdbool.h>


// class
ParserInfo class();
ParserInfo memberDeclar();
ParserInfo classVarDeclar();
ParserInfo subroutineDeclar();
ParserInfo type();
ParserInfo paramList();
ParserInfo subroutineBody();
ParserInfo statement();

// statements
ParserInfo varDeclarStatement();
ParserInfo letStatement();
ParserInfo ifStatement();
ParserInfo whileStatement();
ParserInfo doStatement();
ParserInfo returnStatement();
ParserInfo expression();
ParserInfo subroutineCall();
ParserInfo expressionList();

// expressions
ParserInfo relationalExpression();
ParserInfo ArithmeticExpression();
ParserInfo term();
ParserInfo factor();
ParserInfo operand();

// error declar
void error(const char *, Token);

void error(const char *msg, Token t)
{
	exit(0);
}

ParserInfo pi2; //this is the second pi, used to implement recursive descent parsing
int braces = 0;


ParserInfo class()
{
	Token t;
	ParserInfo pi;
	// printf("\n\n\n\n\n\n");

	t = GetNextToken();
	

	/*if its lexer error*/

	if (t.tp == ERR)
	{
		pi.er = lexerErr;
		pi.tk = t;
		return pi;
	}

	/*class*/

	if (t.tp == RESWORD && strcmp(t.lx, "class") == 0)
	{
		// first word is class
	}
	else
	{
		pi.er = classExpected;
		pi.tk = t;
		return pi;
	}

	t = GetNextToken();

	/*identifier*/

	if (t.tp == ID)
	{
		// second word is an id
	}
	else
	{
		pi.er = idExpected;
		pi.tk = t;
		return pi;
	}

	t = GetNextToken();

	/*{*/

	// Token t;
	if (t.tp == SYMBOL && (strcmp(t.lx, "{") == 0))
	{
		// is right
		braces += 1;
		t = PeekNextToken();
		while (strcmp(t.lx, "}") != 0 && t.tp != EOFile)
		{

			if (t.tp == ERR)
			{
				t = GetNextToken();
				pi.er = lexerErr;
				pi.tk = t;
				return pi;
			}
			pi2 = memberDeclar();
			if (pi2.er != none)
			{
				return pi2;
			}
			t = PeekNextToken();
		}

		if (t.tp == SYMBOL && (strcmp(t.lx, "}") == 0) && braces == 1)
		{
			braces -= 1;

			t = GetNextToken();

			pi.er = none;
			pi.tk = t;
			return pi;
		}
		else if (t.tp == EOFile)
		{
			pi.er = closeBraceExpected;
			pi.tk = t;
			return pi;
		}
	}

	else
	{
		pi.er = openBraceExpected;
		pi.tk = t;
		return pi;
	}

	
	// printf("\n\n\n\n\n\n");
}

ParserInfo type()
{
	Token t;
	ParserInfo pi;
	t = GetNextToken();
	if (t.tp ==  RESWORD && strcmp(t.lx, "int")==0)
	{
		// we got int
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else if (t.tp == RESWORD && strcmp(t.lx, "char")==0)
	{
		// we got char
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else if (t.tp == RESWORD && strcmp(t.lx, "boolean")==0)
	{
		// we got boolean
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else if (t.tp == ID)
	{
		// we got id
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else
	{
		pi.er = illegalType;
		pi.tk = t;
		return pi;
	}
}

// classVarDeclar -> (static | field) type identifier {, identifier} ;

ParserInfo classVarDeclar()
{
	Token t;
	ParserInfo pi;
	t = GetNextToken();

	if (t.tp == RESWORD && strcmp(t.lx, "static") == 0)
	{
		// pi.er = none;
		// pi.tk = t;
		// return pi;
	}
	else if (t.tp == RESWORD && strcmp(t.lx, "field") == 0)
	{
		// pi.er = none;
		// pi.tk = t;
		// return pi;
	}
	else
	{
		pi.er = classVarErr;
		pi.tk = t;
		return pi;
	}

	
	pi2 = type();
	if (pi2.er != none)
	{
		return pi2;
	}

	t = GetNextToken();

	if (t.tp == ID)
	{
		// pi.er = none;
		// pi.tk = t;
		// return pi;
	}
	else
	{
		pi.er = idExpected;
		pi.tk = t;

		return pi;
	}
	t = PeekNextToken();

	while (strcmp(t.lx, ",") == 0)
	{

		if (t.tp == SYMBOL && strcmp(t.lx, ",")==0)
		{

			t = GetNextToken();
			t = GetNextToken();
			if (t.tp == ERR)
			{
				pi.er = lexerErr;
				pi.tk = t;
				return pi;
			}
			else if (t.tp == ID)
			{
				// pi.er = none;
				// pi.tk = t;
			}
			else
			{
				pi.er = idExpected;
				pi.tk = t;
				return pi;
			}

			t = PeekNextToken();
		}
	}

	t = GetNextToken();
	
	if (t.tp == SYMBOL && strcmp(t.lx, ";")==0)
	{
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else
	{
		pi.er = semicolonExpected;
		pi.tk = t;
		return pi;
	}
	// return pi;
}

ParserInfo subroutineDeclar()
{
	ParserInfo pi;
	Token t;

	t = GetNextToken();
	if (t.tp == RESWORD && strcmp(t.lx, "constructor") == 0)
	{
		//valid
	}
	else if (t.tp == RESWORD && strcmp(t.lx, "function") == 0)
	{
		//valid
	}
	else if (t.tp == RESWORD && strcmp(t.lx, "method") == 0)
	{
		//valid
	}
	else
	{
		//invalid
		pi.er = subroutineDeclarErr;
		pi.tk = t;

		return pi;
	}

	t = PeekNextToken();

	if (t.tp == RESWORD && strcmp(t.lx, "void") == 0)

	{
		t = GetNextToken();
	}
	else
	{
		pi2 = type();
		if (pi2.er != none)
		{

			return pi2;
		}
	}
	t = GetNextToken();

	if (t.tp == ID)
	{
	}
	else
	{

		pi.er = idExpected;
		pi.tk = t;
		return pi;
	}
	t = GetNextToken();

	if (t.tp == SYMBOL && strcmp(t.lx, "(") == 0)
	{

		pi2 = paramList();
		// printf("TOken in subroutinedeclar %s\n",pi2.tk.lx);
		if (pi2.er != none)
		{
			return pi2;
		}
	}
	else
	{

		pi.er = openParenExpected;
		pi.tk = t;
		return pi;
	}

	t = PeekNextToken();


	if (t.tp == SYMBOL && strcmp(t.lx, ")")==0)
	{
		//parenthesis is closed
	}
	else
	{
		//missing parenthesis
		pi.er = closeParenExpected;
		pi.tk = t;
		return pi;
	}

t = GetNextToken();
	// printf("6)TOken in Paramlist %s\n",t.lx);
	//printf("\ntoken before %s on line %i\n", t.lx, t.ln);
	
	pi2 = subroutineBody();

//	printf("\ntoken after %s on line %i\n", t.lx, t.ln);

	if (pi2.er != none)
	{
		return pi2;
	}

	pi.er = none;
	pi.tk = t;

	return pi;
}

ParserInfo paramList()
{
	ParserInfo pi;
	Token t;
	t = PeekNextToken();


if((strcmp(t.lx,")"))==0)
{
	pi.er = none;
	pi.tk = t;
	return pi;

}
if((strcmp(t.lx,"{")==0)||!(strcmp(t.lx,";")))
{
	pi.er = closeParenExpected;
	pi.tk = t;
	return pi;
}




	pi2 = type();
	if(pi2.er!=none)
	{
		return pi2;
	}

	t = GetNextToken();
	if (t.tp == ID)
	{
		// printf("TOken in Paramlist %s\n",t.lx);
	}
	else
	{
		pi.er = idExpected;
		pi.tk = t;
		return pi;
	}
	
	t = PeekNextToken();
	while (strcmp(t.lx, ",") == 0)
	{

		if (t.tp == SYMBOL && !strcmp(t.lx, ","))
		{
			t = GetNextToken();
			type();
			t = GetNextToken();

			if (t.tp == ID)
			{
				pi.er = none;
				pi.tk = t;
			}
			else
			{
				pi.er = idExpected;
				pi.tk = t;
				return pi;
			}
		t = PeekNextToken();
		}

	}

	pi.er = none;
	pi.tk = t;
	return pi;

}

ParserInfo subroutineBody()
{
	Token t;
	ParserInfo pi;

	t = GetNextToken();
	
	// printf("\ntoken before %s on line %i\n", t.lx, t.ln);
	if (t.tp == SYMBOL && strcmp(t.lx, "{") == 0)
	{

		braces += 1;
	}
	else
	{

		pi.er = openBraceExpected;
		pi.tk = t;
		return pi;
	}

	t = PeekNextToken();

	while (t.tp != EOFile && strcmp(t.lx, "}") != 0)
	{

		if (t.tp == ERR)
		{
			pi.er = lexerErr;
			pi.tk = t;
			return pi;
		}

		pi2 = statement();

		if (pi2.er != none)
		{

			return pi2;
		}

		t = PeekNextToken();
	}

	t = GetNextToken();

	if (t.tp == SYMBOL && strcmp(t.lx, "}") == 0)
	{

		// t = GetNextToken();
		braces -= 1;

		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else
	{

		pi.er = closeBracketExpected;
		pi.tk = t;
		return pi;
	}
}

ParserInfo memberDeclar()
{
	Token t;
	ParserInfo pi;
	t = PeekNextToken();
	if (strcmp(t.lx, "static") == 0 || strcmp(t.lx, "field") == 0)
	{

		pi2 = classVarDeclar();
		if (pi2.er != none)
		{
			return pi2;
		}

		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else if (strcmp(t.lx, "constructor") == 0 || strcmp(t.lx, "function") == 0 || strcmp(t.lx, "method") == 0)
	{

		pi2 = subroutineDeclar();

		if (pi2.er != none)
		{
			return pi2;
		}

		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else
	{
		pi.er = memberDeclarErr;
		pi.tk = t;
		return pi;
	}
}




/** STATEMENT GRAMMAR **/

ParserInfo statement()
{
	ParserInfo pi;
	Token t;
	t = PeekNextToken();

	if (strcmp(t.lx, "var") == 0)
	{
		pi2 = varDeclarStatement();
		if (pi2.er != none)
		{
			return pi2;
		}
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else if (strcmp(t.lx, "let") == 0)
	{
		pi2 = letStatement();
		if (pi2.er != none)
		{
			return pi2;
		}
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else if (strcmp(t.lx, "if") == 0)
	{
		pi2 = ifStatement();
		if (pi2.er != none)
		{
			return pi2;
		}
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else if (strcmp(t.lx, "while") == 0)
	{
		pi2 = whileStatement();
		if (pi2.er != none)
		{
			return pi2;
		}
	}
	else if (strcmp(t.lx, "do") == 0)
	{
		pi2 = doStatement();
		if (pi2.er != none)
		{
			return pi2;
		}
		pi.er = none;
		pi.tk = t;
		return pi;
	}

	else if (strcmp(t.lx, "return") == 0)
	{
		pi2= returnStatement();
		if (pi2.er != none)
		{
			return pi2;
		}
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else
	{

		pi.er = syntaxError; // is this the right error? update: yes it is
		pi.tk = t;
		return pi;
	}
}

ParserInfo varDeclarStatement()
{
	ParserInfo pi;
	Token t;
	t = GetNextToken();

	if (t.tp == RESWORD && strcmp(t.lx, "var") == 0)
	{
		
	}
	else
	{
		pi.er = syntaxError;
		pi.tk = t;
		return pi;
	}

	pi2 = type();
	if (pi2.er != none)
	{
		return pi2;
	}

	t = GetNextToken();

	if (t.tp == ID)
	{
		
	}
	else
	{
		pi.er = idExpected;
		pi.tk = t;
		return pi;
	}

	t = PeekNextToken();
	while (strcmp(t.lx, ",") == 0 && t.tp != EOFile)
	{
		t = GetNextToken();
		if (t.tp == SYMBOL && strcmp(t.lx, ",") == 0)
		{
			t = GetNextToken();
			if (t.tp == ID)
			{
				
			}
			else if (t.tp == ERR)
			{
				pi.er = lexerErr;
				pi.tk = t;
				return pi;
			}
			else
			{
				pi.er = idExpected;
				pi.tk = t;
				return pi;
			}
			t = PeekNextToken();
		}
	}
	t = GetNextToken();

	if (t.tp == SYMBOL && strcmp(t.lx, ";") == 0)
	{
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else
	{
		pi.er = semicolonExpected;
		pi.tk = t;
		return pi;
	}
}

ParserInfo letStatement()
{
	ParserInfo pi;
	Token t;
	t = GetNextToken();

	if (t.tp == RESWORD && strcmp(t.lx, "let") == 0)
	{
		
	}
	else
	{
		pi.er = syntaxError;
		pi.tk = t;
		return pi;
	}

	t = GetNextToken();

	if (t.tp == ID)
	{
		
	}
	else
	{
		pi.er = idExpected;
		pi.tk = t;
		return pi;
	}

	t = PeekNextToken();	
	if (t.tp == SYMBOL && strcmp(t.lx, "[") == 0)
	{
		t = GetNextToken();

		pi2 = expression();
		if (pi2.er != none)
		{
			return pi2;
		}
		t = GetNextToken();
		if (t.tp == SYMBOL && strcmp(t.lx, "]") == 0)
		{
			
		}
		else
		{
			pi.er = closeBracketExpected;
			pi.tk = t;
			return pi;
		}
		t = PeekNextToken();
	}

	if (t.tp == SYMBOL && strcmp(t.lx, "=") == 0)
	{
		t = GetNextToken();
	}	
	else
	{
		pi.er = equalExpected;
		pi.tk = t;
		return pi;
	}
	pi2 = expression();
	if (pi2.er != none)
	{
		return pi2;
	}
	t = GetNextToken();
	if (strcmp(t.lx, ";") == 0)
	{
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else
	{
		pi.er = semicolonExpected;
		pi.tk = t;
		return pi;
	}


}




ParserInfo ifStatement()
{
	ParserInfo pi;
	Token t;
	t = GetNextToken();
	if (strcmp(t.lx, "if") == 0)
	{
	}
	else
	{
		pi.er = syntaxError;
		pi.tk = t;
		return pi;
	}

	t = GetNextToken();
	if (t.tp == SYMBOL && strcmp(t.lx, "(") == 0)
	{
		pi2 = expression();
		if (pi2.er != none)
		{
			return pi2;
		}
		t = GetNextToken();

		if (t.tp == SYMBOL && strcmp(t.lx, ")") == 0)
		{
			
			pi.er = none;
			pi.tk = t;
		}
		else
		{
			pi.er = closeParenExpected;
			pi.tk = t;
			return pi;
		}
	}
	else
	{
		pi.er = openParenExpected;
		pi.tk = t;
		return pi;
	}

	t = GetNextToken();
	if (t.tp == SYMBOL && strcmp(t.lx, "{") == 0)
	{

		braces += 1;
		t = PeekNextToken();
		while (t.tp != EOFile && strcmp(t.lx, "}") != 0)
		{

			if (t.tp == ERR)
			{
				pi.er = lexerErr;
				pi.tk = t;
				return pi;
			}

			pi2 = statement();

			if (pi2.er != none)
			{
				return pi2;
			}

			t = PeekNextToken();
		}
		t = GetNextToken();
		if (t.tp == SYMBOL && strcmp(t.lx, "}") == 0)
		{
			
			braces -= 1;
		}
		else
		{
			pi.er = closeBraceExpected;
			pi.tk = t;
			return pi;
		}
	}
	else
	{
		pi.er = openBraceExpected;
		pi.tk = t;
		return pi;
	}

	t = PeekNextToken();

	if (t.tp == RESWORD && strcmp(t.lx, "else") == 0)
	{
		t = GetNextToken();
		t = GetNextToken();
		if (t.tp == SYMBOL && strcmp(t.lx, "{") == 0)
		{
			braces += 1;
			t = PeekNextToken();
			while (t.tp != SYMBOL && strcmp(t.lx, "}") != 0)
			{

				if (t.tp == ERR)
				{
					pi.er = lexerErr;
					pi.tk = t;
					return pi;
				}

				pi2 = statement();

				if (pi2.er != none)
				{
					return pi2;
				}
				t = PeekNextToken();
			}

			t = GetNextToken();

			if (t.tp == SYMBOL && strcmp(t.lx, "}") == 0)
			{
				
				braces -= 1;
				pi.er = none;
				pi.tk = t;
				return pi;
			}
			else
			{
				pi.er = closeBraceExpected;
				pi.tk = t;
				return pi;
			}
		}
		else
		{
			pi.er = openBraceExpected;
			pi.tk = t;
			return pi;
		}
	}
	pi.er = none;
	pi.tk = t;
	return pi;
}

ParserInfo whileStatement()
{
	ParserInfo pi;
	Token t;
	t = GetNextToken();

	if (t.tp == RESWORD && strcmp(t.lx, "while") == 0)
	{

		t = GetNextToken();
		if (t.tp == SYMBOL && strcmp(t.lx, "(") == 0)
		{

			pi2 = expression();
			if (pi2.er != none)
			{
				return pi2;
			}
			t = GetNextToken();

			if (t.tp == SYMBOL && strcmp(t.lx, ")") == 0)
			{
			}
			else
			{
				pi.er = closeParenExpected;
				pi.tk = t;
				return pi;
			}
		}
		else
		{
			pi.er = openParenExpected;
			pi.tk = t;
			return pi;
		}

		t = GetNextToken();
		if (t.tp == SYMBOL && strcmp(t.lx, "{") == 0)
		{
			braces += 1;
			t = PeekNextToken();

			while (t.tp != EOFile && strcmp(t.lx, "}") != 0)
			{
				if (t.tp == ERR)
				{
					pi.er = lexerErr;
					pi.tk = t;
					return pi;
				}
				pi2=statement();
				if (pi2.er != none)
				{
					return pi2;
				}
				t = PeekNextToken(); // might not need this, update: it's required
			}
			t = GetNextToken();
			if (t.tp == SYMBOL && strcmp(t.lx, "}") == 0)
			{
				braces -= 1;
				pi.er = none;
				pi.tk = t;
				return pi;
			}
			else
			{
				pi.er = closeBraceExpected;
				pi.tk = t;
				return pi;
			}
		}
		else
		{
			pi.er = openBraceExpected;
			pi.tk = t;
			return pi;
		}
	}
	else
	{
		pi.er = syntaxError;
		pi.tk = t;
		return pi;
	}
}

ParserInfo doStatement()
{
	
	ParserInfo pi;
	Token t;
	t = GetNextToken();

	if (t.tp == RESWORD && strcmp(t.lx, "do") == 0)
	{
	}
	else
	{
		pi.er = syntaxError;
		pi.tk = t;
		return pi;
	}


	pi2 = subroutineCall();

	if (pi2.er != none)
	{
		return pi2;
	}

	t = GetNextToken();
	// printf("Checking for semi-colon %s\n",t.lx);

	if (t.tp == SYMBOL && strcmp(t.lx, ";") == 0)
	{
		
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else
	{
		pi.er = semicolonExpected;
		pi.tk = t;
		return pi;
	}
}

ParserInfo subroutineCall()

{

	ParserInfo pi;
	Token t;
	t = GetNextToken();

	if (t.tp == ID)
	{
	}
	else
	{
		pi.er = idExpected;
		pi.tk = t;
		return pi;
	}
	t = PeekNextToken();
	if (!strcmp(t.lx, "."))
	{
		t = GetNextToken();
		t = GetNextToken();
		if (t.tp == ID)
		{

		}
		else
		{
			pi.er = idExpected;
			pi.tk = t;
			return pi;
		}
	}
	t = GetNextToken();

	if (t.tp == SYMBOL && strcmp(t.lx, "(") == 0)
	{
	}
	else
	{
		pi.er = openParenExpected;
		pi.tk = t;
		return pi;
	}
	//t = PeekNextToken(); //unnecessary
	pi2 = expressionList();
	if (pi2.er != none)
	{
		return pi2;
	}

	t = GetNextToken();

	if (t.tp == SYMBOL && strcmp(t.lx, ")") == 0)
	{
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else
	{
		pi.er = closeParenExpected;
		pi.tk = t;
		return pi;
	}
}

ParserInfo expressionList()
{
	ParserInfo pi;
	Token t;
	t = PeekNextToken();
	if (strcmp(t.lx, ")") == 0)
	{
		pi.er = none;
		pi.tk = t;
		return pi;
	}

	pi2 = expression();
	if (pi2.er != none)
	{
		return pi2;
	}
	t = PeekNextToken();
	
	// printf("1 THe token in expressionList is %s the line is %i \n",t.lx, t.ln);
	if (strcmp(t.lx, ",")==0)
	{
		while (strcmp(t.lx, ",") == 0 && t.tp != EOFile)
		{
			t = GetNextToken();
			
	// printf("2 THe token in expressionList is %s the line is %i \n",t.lx, t.ln);
			pi2 = expression();
			if (pi2.er != none)
			{
				return pi2;
			}
			t = PeekNextToken();
		}
		if (t.tp == ERR)
		{
			pi.er = lexerErr;
			pi.tk = t;
			return pi;
		}
		if (t.tp == EOFile)
		{
			pi.er = closeParenExpected;

			pi.tk = t;
			return pi;
		}
	}
	if (strcmp(t.lx, ")") == 0)
	{

		pi.er = none;
		pi.tk = t;
		return pi;
	}
}

ParserInfo returnStatement()
{
	ParserInfo pi;
	Token t;
	t = GetNextToken();

	if (t.tp == RESWORD && strcmp(t.lx, "return") == 0)
	{
	}
	else
	{
		pi.er = syntaxError;
		pi.tk = t;
		return pi;
	}
	t = PeekNextToken();
	if (strcmp(t.lx, ";") == 0)
	{
		//
		t = GetNextToken();
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else if (strcmp(t.lx, "}") == 0)
	{
		t = GetNextToken();
		pi.er = semicolonExpected;
		pi.tk = t;
		return pi;
	}
	else
	{
		pi2 = expression();
		if (pi2.er != none)
		{
			return pi2;
		}
	}
	t = GetNextToken();

	if (strcmp(t.lx, ";") == 0)
	{
		//
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else
	{
		pi.er = semicolonExpected;
		pi.tk = t;
		return pi;
	}
}



/* EXPRESSIONS GRAMMAR*/

ParserInfo expression()
{
	ParserInfo pi;
	Token t;

	pi2 = relationalExpression();
	if (pi2.er != none)
	{
		return pi2;
	}
	t = PeekNextToken();

	while (t.tp != EOFile && (strcmp(t.lx, "|") == 0 || strcmp(t.lx, "&") == 0))
	{
		t = GetNextToken();

		pi2 = relationalExpression();
		if (pi2.er != none)
		{
			return pi2;
		}
		t = PeekNextToken();
	}

	if (t.tp == EOFile)
	{
		pi.er = syntaxError;
		pi.tk = t;
		return pi;
	}

	if (t.tp == ERR)
	{
		pi.er = lexerErr;
		pi.tk = t;
		return pi;
	}
	pi.er = none;
	pi.tk = t;

	return pi;
}

ParserInfo relationalExpression()
{
	ParserInfo pi;
	Token t;
	t = PeekNextToken();
	// printf("The token inside of relationalexpression is %s\n",t.lx);

	pi2 = ArithmeticExpression();
	if (pi2.er != none)
	{
		return pi2;
	}

	t = PeekNextToken();

	while (t.tp != EOFile && t.tp == SYMBOL && (strcmp(t.lx, "=") == 0 || strcmp(t.lx, ">") == 0 || strcmp(t.lx, "<") == 0))
	{
		t = GetNextToken();
		pi2 = ArithmeticExpression();
		if (pi2.er != none)
		{
			return pi2;
		}
		t = PeekNextToken();
	}

	if (t.tp == EOFile)
	{
		pi.er = syntaxError;
		pi.tk = t;
		return pi;
	}
	if (t.tp == ERR)
	{
		pi.er = lexerErr;
		pi.tk = t;
		return pi;
	}
	pi.er = none;
	pi.tk = t;
	return pi;
}

ParserInfo ArithmeticExpression()
{
	ParserInfo pi;
	Token t;


	pi2 = term();
	if (pi2.er != none)
	{
		return pi2;
	}

	t = PeekNextToken();

	while (t.tp != EOFile && t.tp == SYMBOL && (strcmp(t.lx, "+") == 0 || strcmp(t.lx, "-") == 0))
	{
		t = GetNextToken();
		pi2 = term();

		if (pi2.er != none)
		{
			return pi2;
		}

		t = PeekNextToken();
	}

	if (t.tp == EOFile)
	{
		pi.er = syntaxError;
		pi.tk = t;
		return pi;
	}
	if (t.tp == ERR)
	{
		pi.er = lexerErr;
		pi.tk = t;
		return pi;
	}
	pi.er = none;
	pi.tk = t;
	return pi;	

	pi2 = factor();

	if (pi2.er != none)
	{
		return pi2;
	}

	t = PeekNextToken();

	while (t.tp != EOFile && t.tp == SYMBOL && (strcmp(t.lx, "*") == 0 || strcmp(t.lx, "/") == 0))
	{
		t = GetNextToken();
		pi2 = factor();

		if (pi2.er != none)
		{
			return pi2;
		}
		t = PeekNextToken();
	}

	if (t.tp == EOFile)
	{
		pi.er = syntaxError;
		pi.tk = t;
		return pi;
	}
	if (t.tp == ERR)
	{
		pi.er = lexerErr;
		pi.tk = t;
		return pi;
	}
	pi.er = none;
	pi.tk = t;
	return pi;
}

ParserInfo term()
{

 ParserInfo pi;
 Token t;

 pi2 = factor();

 if (pi2.er != none)
 {
 return pi2;
 }

 t = PeekNextToken();

 while (t.tp != EOFile && t.tp == SYMBOL && (strcmp(t.lx, "*") == 0 || strcmp(t.lx, "/") == 0))
 {
 t = GetNextToken();
 pi2 = factor();

 if (pi2.er != none)
 {
 return pi2;
 }
 t = PeekNextToken();
 }

 if (t.tp == EOFile)
 {
 pi.er = syntaxError;
 pi.tk = t;
 return pi;
 }
 if (t.tp == ERR)
 {
 pi.er = lexerErr;
 pi.tk = t;
 return pi;
 }
 pi.er = none;
 pi.tk = t;
 return pi;
}







ParserInfo factor()
{
	
	ParserInfo pi;
	Token t;


	t = PeekNextToken();
	if ((t.tp == SYMBOL) && ((strcmp(t.lx, "-") == 0) || (strcmp(t.lx, "~") == 0)))
		{
			t = GetNextToken();
		
		
		pi2 = operand();

		if (pi2.er != none)
		{
			return pi2;
		}

		pi.er = none;
		pi.tk = t;
		return pi;
		}
	
	else
	{
		// even with empty string, operand();
		pi2 = operand();
		if (pi2.er != none)
		{
			return pi2;
		}
		pi.er = none;
		pi.tk = t;
		return pi;
	}
}




ParserInfo operand()
{

	ParserInfo pi;
	Token t;
	t = PeekNextToken();
	if (t.tp == INT)
	{
		
		t = GetNextToken();
		pi.er = none;
		pi.tk = t;
		return pi;
	}
	else if (t.tp == ID)
	{
		
		t = GetNextToken();
		
		t = PeekNextToken();
		
		if (t.tp == SYMBOL && strcmp(t.lx, ".") == 0)
		{
			// just getting the dot
			t = GetNextToken();
			
			// now getting the thing after the dot
			t = GetNextToken();
			

			if (t.tp == ID)
			{
			}
			// else		//not needed
			// {
			// 	pi.er = idExpected;
			// 	pi.tk = t;
			// 	return pi;
			// } 
		}
		t = PeekNextToken();
			if (strcmp(t.lx, "[") == 0)
			{

				t = GetNextToken();
				pi2 = expression();
				if (pi2.er != none)
				{
					return pi2;
				}
				t = GetNextToken();

				if (t.tp == SYMBOL && strcmp(t.lx, "]") == 0)
				{
				}
				else
				{
					pi.er = closeBracketExpected;
					pi.tk = t;
					return pi;
				}
			}
			else if (strcmp(t.lx, "(") == 0)
			{
				t = GetNextToken();
				pi2 = expressionList();

				if (pi2.er != none)
				{
					return pi2;
				}
				t = GetNextToken();

				if (t.tp == SYMBOL && strcmp(t.lx, ")") == 0)
				{
				}
				else
				{
					pi.er = closeParenExpected;
					pi.tk = t;
					return pi;
				}
			}
			pi.er = none;
			pi.tk = t;
			return pi;
			
		}else if (strcmp(t.lx, "(") == 0)
			{
				
				t = GetNextToken();
				pi2 = expression();
				if (pi2.er != none)
				{
					return pi2;
				}



				t = GetNextToken();

				if (strcmp(t.lx, ")") == 0)
				{
					pi.er = none;
					pi.tk = t;
					return pi;
				}
				else
				{
					pi.er = closeParenExpected;
					pi.tk = t;
					return pi;
				}
			}
		

		else if (t.tp == STRING)
		{
			t = GetNextToken();
			pi.er = none;
			pi.tk = t;
			return pi;
		}
		else if (strcmp(t.lx, "true") == 0)
		{
			t = GetNextToken();
			pi.er = none;
			pi.tk = t;
			return pi;
		}
		else if (strcmp(t.lx, "false") == 0)
		{
			t = GetNextToken();
			pi.er = none;
			pi.tk = t;
			return pi;
		}
		else if (strcmp(t.lx, "null") == 0)
		{
			t = GetNextToken();
			pi.er = none;
			pi.tk = t;
			return pi;
		}
		else if (strcmp(t.lx, "this") == 0)
		{
			t = GetNextToken();
			pi.er = none;
			pi.tk = t;
			return pi;
		}
		else
		{
			pi.er = syntaxError;
			pi.tk = t;
			return pi;
			// so it HAS to be one of the above
		}
	}

	int InitParser(char *file_name)
	{
		return InitLexer(file_name);
	}

	ParserInfo Parse()
	{
		ParserInfo pi;

		// implement the function
		pi = class();
		return pi;
	}

	int StopParser()
	{
		return StopLexer();
	}

#ifndef TEST_PARSER

	// int main()
	// {

	// 	// printf("\nTESTING PARSER\n\n");

	// 	Token t;
	// 	ParserInfo pi;
	// 	setbuf(stdout, NULL);

	// 	InitParser("closeBracketExpected.jack");

	// 	pi = Parse();
	// 	printf("\n\n\nError Type: %s, line: %i, token: %s, \n\n\n", ErrorString(pi.er), pi.tk.ln, pi.tk.lx);

	// 	StopParser();

	// 	return 1;
	// }
#endif
