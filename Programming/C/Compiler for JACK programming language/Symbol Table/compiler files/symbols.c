
/************************************************************************
University of Leeds
School of Computing
COMP2932- Comstler Design and Construction
The Symbol Tables Module

I confirm that the following code has been developed and written by me and it is entirely the result of my own work.
I also confirm that I have not costed any parts of this program from another person or any other source or facilitated someone to copy this program from me.
I confirm that I will not publish the program online or share it with anyone without permission of the module leader.

Student Name:Farha Rashid Sayed
Student ID:201548827
Email:sc21frs@leeds.ac.uk
Date Work Commenced:
*************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbols.h"


////////////////

#include "lexer.h"
#include "lexer.c"
#include "parser.h"
 #include "parser.c"


//draft  3

/**

// class
SymbolTable class1();
SymbolTable memberDeclar1();
SymbolTable classVarDeclar1();
SymbolTable subroutineDeclar1();
SymbolTable type1();
SymbolTable paramList1();
SymbolTable subroutineBody1();
SymbolTable statement1();

// statements
SymbolTable varDeclarStatement1();
SymbolTable letStatement1();
SymbolTable ifStatement1();
SymbolTable whileStatement1();
SymbolTable doStatement1();
SymbolTable returnStatement1();
SymbolTable expression1();
SymbolTable subroutineCall1();
SymbolTable expressionList1();

// expressions
SymbolTable relationalExpression1();
SymbolTable ArithmeticExpression1();
SymbolTable term1();
SymbolTable factor1();
SymbolTable operand1();


    SymbolTable st2;
    int braces1 = 0; 


     char *symbolsfound[] = {};  //variable name
    int symbolline[] = {};
    char *symboltype[] = {}; 
    char sorf[] = {}; //static='s' or field='f' or argument='a' or variable='v' or subroutine='r'
   int INDEX = 0;
SymbolTable functionalpart()
{
    SymbolTable st;
    Token t;
    



























    //the code has already been parsed at this point
    // char *symbolsfound[] = {};  //variable name
    // int symbolline[] = {};
    // char *symboltype[] = {}; 
    // char sorf[] = {}; //static='s' or field='f' or argument='a' or variable='v' or subroutine='r'
    //we shall go through it using the lexer
    t = GetNextToken();
    



    while(t.tp!=EOFile) //it wont be ERR cause its been parsed
    {
        t = GetNextToken();

        if(t.tp == ID)
        {

            for(int a; a<INDEX; a++)
            {
                if(strcmp(t.lx,*symbolsfound[a]) == 0 && symboltype[INDEX] ==t.tp)
                {
                    //skip it
                }
                else
                {
                    //add it
            symbolsfound[INDEX] = t.lx;
            symbolline[INDEX] = t.ln;
            symboltype[INDEX] = TokenTypeString(t.tp);
            INDEX+=1;
                }
            }


        }
        else
        {
            st.ef = te; //symboltable.errorfound = temporaryerror
            return st;
        }



    }

    if(t.tp == EOFile)
    {
        //the symbol table's been constructed
    }







    }

///////////////////////////////////////////////////////////////////////
//parser parts






SymbolTable class1()
{
	Token t;
	SymbolTable st;
	t = GetNextToken();
	// first word is class

	t = GetNextToken();
	//name of class, an ID

	t = GetNextToken();
    //curly brace

    
	if (t.tp == SYMBOL && (strcmp(t.lx, "{") == 0))
	{
		// is right
		braces1 += 1;
		t = PeekNextToken();
		while (strcmp(t.lx, "}") != 0 && t.tp != EOFile)
		{
			st2 = memberDeclar1();
            if(st.ef!=none1)
            {
                return st;
            }

			t = PeekNextToken();
		}

		if (t.tp == SYMBOL && (strcmp(t.lx, "}") == 0) && braces1 == 1)
		{
			braces1 -= 1;

			t = GetNextToken();

			st.ef = none1;
			return st;
		}
	}

	
	// printf("\n\n\n\n\n\n");
}

SymbolTable type1()
{
	Token t;
	SymbolTable st;
	t = GetNextToken();

	if (t.tp ==  RESWORD && strcmp(t.lx, "int")==0)
	{
		// we got int
		*symboltype[INDEX] = t.lx;
	}
	else if (t.tp == RESWORD && strcmp(t.lx, "char")==0)
	{
		// we got char
		*symboltype[INDEX] = t.lx;
        
	}
	else if (t.tp == RESWORD && strcmp(t.lx, "boolean")==0)
	{
		// we got boolean
		*symboltype[INDEX] = t.lx;
	}
	if (t.tp == ID)
	{
		// we got id
		*symboltype[INDEX] = t.lx; //maybe its like SymbolTable part of SymbolTable st?
	}
}

// classVarDeclar -> (static | field) type identifier {, identifier} ;

SymbolTable classVarDeclar1()
{
	Token t;
	SymbolTable st;
	t = GetNextToken();

	if (t.tp == RESWORD && strcmp(t.lx, "static") == 0)
	{
		sorf[INDEX] = 's';
	}
	else if (t.tp == RESWORD && strcmp(t.lx, "field") == 0)
	{
		sorf[INDEX] = 'f';
	}

	st2 = type1();
    if(st2.ef!=none1)
    {
        return st2;
    }


	t = GetNextToken();
    //this will be the name of the variable

	if (t.tp == ID)
	{
		*symbolsfound[INDEX] = t.lx;
        symbolline[INDEX] = t.ln;
        INDEX+=1;
	}

	t = PeekNextToken();
    //checking if there's multiple, ex. int a,b = 0;
	while (strcmp(t.lx, ",") == 0)
	{

		if (t.tp == SYMBOL && strcmp(t.lx, ",")==0)
		{

			t = GetNextToken();
			t = GetNextToken();
			 if (t.tp == ID)
			{
				*symbolsfound[INDEX] = t.lx;
                sorf[INDEX] = sorf[INDEX-1]; //same as previous one as we're listing them
                *symboltype[INDEX] = symboltype[INDEX-1]; //same as previous ex. int a,b;
                symbolline[INDEX] = t.ln;
                INDEX+=1;
			}

			t = PeekNextToken();
		}
	}

	t = GetNextToken();
	
	if (t.tp == SYMBOL && strcmp(t.lx, ";")==0)
	{
		//the semicolon
        st.ef = none1;
        return st;
	}
    st.ef = te;
    return st;
}

SymbolTable subroutineDeclar1()
{
	SymbolTable st;
	Token t;

	t = GetNextToken();
    //constructor or function or method 

    sorf[INDEX] = 'r';

	t = PeekNextToken();

	if (t.tp == RESWORD && strcmp(t.lx, "void") == 0)

	{
		t = GetNextToken();
        //void
        *symboltype[INDEX] = t.lx;
	}
    else
    {
st2 = type1();
if(st2.ef!=none1)
{
    return st;
}

    }

	
	t = GetNextToken();
    //name of the constructor or function or method
    //constructors are always called new

	if (t.tp == ID)
	{
        *symbolsfound[INDEX] = t.tp;
        symbolline[INDEX] = t.ln;
        INDEX +=1;
	}

	t = GetNextToken();
    //the ( for method parameters

		st2 = paramList1();
        if(st2.ef!=none1)
        {
            return st2;
        }

	t = GetNextToken();
    //is closing parenthesis


	st2 = subroutineBody1();
    if(st2.ef!=none1)
    {
        return st2;
    }

	return st;
}

SymbolTable paramList1()
{
	SymbolTable st;
	Token t;
	t = PeekNextToken();
    

if((strcmp(t.lx,")"))==0)
{
    st.ef = none1;
    return st;
	//there is no paramlist for the function, we should just quit
    //t = GetNextToken(); //its got in subroutinedeclar
}

else
{
	st2 = type1();
    if(st2.ef!=none1)
    {
        return st2;
    }

	t = GetNextToken();
    //it will be the name of variable in parameters
    sorf[INDEX] = 'a'; //parameter argument
    *symbolsfound[INDEX] = t.lx;
    symbolline[INDEX] = t.ln;
    INDEX+=1;

	t = GetNextToken();
    //maybe there's multiple parameters so it's a comma

	while (strcmp(t.lx, ",") == 0)
	{
		
			st2 = type1();
            if(st2.ef!=none1)
            {
                return st2;
            }

	t = GetNextToken();
    //it will be the name of variable in parameters
    sorf[INDEX] = 'a'; //parameter argument
    *symbolsfound[INDEX] = t.lx;
    symbolline[INDEX] = t.ln;
    INDEX+=1;
		t = PeekNextToken();
		

	}
}
st.ef = none1;
return st;
}

SymbolTable subroutineBody1()
{
	Token t;
	SymbolTable st;

	t = GetNextToken();
    //the open curly bracket
		braces1 += 1;



	t = PeekNextToken();
    //checking if there is any statement, its possible that there isnt one

	while (t.tp != EOFile && strcmp(t.lx, "}") != 0)
	{

		st2 = statement1();
        if(st2.ef!=none1)
        {
            return st2;
        }
		t = PeekNextToken();
	}

	t = GetNextToken();

	if (t.tp == SYMBOL && strcmp(t.lx, "}") == 0)
	{

		// t = GetNextToken();
		braces1  -= 1;
st.ef = none1;

		return st;
	}
    
}

SymbolTable memberDeclar1()
{
	Token t;
	SymbolTable st;
	t = GetNextToken();
    //static or field
	if (strcmp(t.lx, "static") == 0 || strcmp(t.lx, "field") == 0)
	{
		st2 = classVarDeclar1();
        if(st2.ef!=none1)
        {
            return st2;
        }
        
	}
	if (strcmp(t.lx, "constructor") == 0 || strcmp(t.lx, "function") == 0 || strcmp(t.lx, "method") == 0)
	{

		st2 = subroutineDeclar1();
        if(st2.ef!=none1)
        {
            return st2;
        }
        
	}
}








/** STATEMENT GRAMMAR **/

SymbolTable statement1()
{
	SymbolTable st;
	Token t;
	t = PeekNextToken();

	if (strcmp(t.lx, "var") == 0)
	{
		st2 = varDeclarStatement1();
		if(st2.ef!=none1)
        {
            return st2;
        }
		
        st.ef = none1;
		return st;
	}
	else if (strcmp(t.lx, "let") == 0)
	{
		st2= letStatement1();
        if(st2.ef!=none1)
        {
            return st2;
        }
		
        st.ef = none1;
		return st;
	}
	else if (strcmp(t.lx, "if") == 0)
	{
		st2 = ifStatement1();
		if(st2.ef!=none1)
        {
            return st2;
        }
		st.ef = none1;
		return st;
	}
	else if (strcmp(t.lx, "while") == 0)
	{
		st2 = whileStatement1();
		if(st2.ef!=none1)
        {
            return st2;
        
        st.ef = none1;
		return st;
	}
	else if (strcmp(t.lx, "do") == 0)
	{
		st2 = doStatement1();
		if(st2.ef!=none1)
        {
            return st2;
        }
        st.ef = none1;
		return st;
	}

	else if (strcmp(t.lx, "return") == 0)
	{
		st2= returnStatement1();
		if(st2.ef!=none1)
        {
            return st2;
        }
		st.ef = none1;
		return st;
	}
}
}
SymbolTable varDeclarStatement1()
{
	SymbolTable st;
	Token t;
	t = GetNextToken();
    //the word "var"

	st2 = type1();
    if(st2.ef!=none1)
        {
            return st2;
        }
    
	t = GetNextToken();
    //the name of variable

	if (t.tp == ID)
	{
		*symbolsfound[INDEX] = t.lx;
        symbolline[INDEX] = t.ln;
        sorf[INDEX] = 'v';
        INDEX+=1;
	}

	t = PeekNextToken();
	while (strcmp(t.lx, ",") == 0)
	{

		if (t.tp == SYMBOL && strcmp(t.lx, ",")==0)
		{

			t = GetNextToken();
			t = GetNextToken();
			 if (t.tp == ID)
			{
				*symbolsfound[INDEX] = t.lx;
                sorf[INDEX] = sorf[INDEX-1]; //same as previous one as we're listing them
                *symboltype[INDEX] = symboltype[INDEX-1]; //same as previous ex. int a,b;
                symbolline[INDEX] = t.ln;
                INDEX+=1;
			}

			t = PeekNextToken();
		}
	}

	t = GetNextToken();
	
	if (t.tp == SYMBOL && strcmp(t.lx, ";")==0)
	{
		//the semicolon
	}
}

SymbolTable letStatement1()
{
	Token t;
    SymbolTable st;
	t = GetNextToken();
    //the word "let"


	t = GetNextToken();
    //ID = name of variable
char* c;
	for(int a = 0; a<INDEX; a++)
    {
        c = symbolsfound[INDEX];
        if(strcmp(t.lx,c)==0)
        {
            //chilling, we continue to rest of the function
        }
        else
        {
            st.ef = e1; //variable initialized without declaration
            strcpy(st.stt, TokenTypeString(t.tp));
            st.sl = t.ln;
            strcpy(st.sn ,t.lx);
            return st;
        }
    }
  
	t = PeekNextToken();	
    //might or might not have a [

	if (t.tp == SYMBOL && strcmp(t.lx, "[") == 0)
	{
		t = GetNextToken();
        //got the [

		st2 = expression1();
if(st2.ef!=none1)
        {
            return st2;
        }

		t = GetNextToken();
		if (t.tp == SYMBOL && strcmp(t.lx, "]") == 0)
		{
			
		}
		t = PeekNextToken();
	}

	if (t.tp == SYMBOL && strcmp(t.lx, "=") == 0)
	{
		t = GetNextToken();
	}	
	st2 = expression1();

	if (st2.ef != none1)
	{
		return st2;
	}
	t = GetNextToken();
	if (strcmp(t.lx, ";") == 0)
	{
		st.ef = none1;
		return st;
	}

}




SymbolTable ifStatement1()
{
	SymbolTable st;
	Token t;
	t = GetNextToken();
	if (strcmp(t.lx, "if") == 0)
	{
	}

	t = GetNextToken();
	if (t.tp == SYMBOL && strcmp(t.lx, "(") == 0)
	{
		st2 = expression1();
		if (st2.ef != none1)
		{
			return st2;
		}
		t = GetNextToken();

		if (t.tp == SYMBOL && strcmp(t.lx, ")") == 0)
		{
			
		}
	}

	t = GetNextToken();
	if (t.tp == SYMBOL && strcmp(t.lx, "{") == 0)
	{

		braces1 += 1;
		t = PeekNextToken();
		while (t.tp != EOFile && strcmp(t.lx, "}") != 0)
		{

			st2 = statement1();

			if (st2.ef != none1)
			{
				return st2;
			}

			t = PeekNextToken();
		}
		t = GetNextToken();
		if (t.tp == SYMBOL && strcmp(t.lx, "}") == 0)
		{
			
			braces1  -= 1;
		}
	}

	t = PeekNextToken();

	if (t.tp == RESWORD && strcmp(t.lx, "else") == 0)
	{
		t = GetNextToken();
		t = GetNextToken();
		if (t.tp == SYMBOL && strcmp(t.lx, "{") == 0)
		{
			braces1  += 1;
			t = PeekNextToken();
			while (t.tp != SYMBOL && strcmp(t.lx, "}") != 0)
			{
				st2 = statement1();

				if (st2.ef != none1)
				{
					return st2;
				}
				t = PeekNextToken();
			}

			t = GetNextToken();

			if (t.tp == SYMBOL && strcmp(t.lx, "}") == 0)
			{
				
				braces1  -= 1;
                
				return st;
			}
            
		}
        
	}
	st.ef = none1;

	return st;
}

SymbolTable whileStatement1()
{
	SymbolTable st;
	Token t;
	t = GetNextToken();

	if (t.tp == RESWORD && strcmp(t.lx, "while") == 0)
	{

		t = GetNextToken();
		if (t.tp == SYMBOL && strcmp(t.lx, "(") == 0)
		{

			st2 = expression1();
			if (st2.ef != none1)
			{
				return st2;
			}
			t = GetNextToken();

			if (t.tp == SYMBOL && strcmp(t.lx, ")") == 0)
			{
			}
			}
		}

		t = GetNextToken();
		if (t.tp == SYMBOL && strcmp(t.lx, "{") == 0)
		{
			braces1 += 1;
			t = PeekNextToken();

			while (t.tp != EOFile && strcmp(t.lx, "}") != 0)
			{
				
				st=statement1();
				if (st.ef != none1)
				{
					return st;
				}
				t = PeekNextToken(); // might not need this, update: it's required
			}
			t = GetNextToken();
			if (t.tp == SYMBOL && strcmp(t.lx, "}") == 0)
			{
				braces1 -= 1;
				return st;
			}
		}
	}


SymbolTable doStatement1()
{
	
	SymbolTable st;
	Token t;
	t = GetNextToken();

	if (t.tp == RESWORD && strcmp(t.lx, "do") == 0)
	{
	}


	st2 = subroutineCall1();

	if (st2.ef != none1)
	{
		return st2;
	}

	t = GetNextToken();
	// printf("Checking for semi-colon %s\n",t.lx);

	if (t.tp == SYMBOL && strcmp(t.lx, ";") == 0)
	{
		st.ef = none1;
		return st;
	}
}

SymbolTable subroutineCall1()

{

	SymbolTable st;
	Token t;
	t = GetNextToken();

	if (t.tp == ID)
	{
	}
	t = PeekNextToken();
	if (!strcmp(t.lx, "."))
	{
		t = GetNextToken();
		t = GetNextToken();
		if (t.tp == ID)
		{

		}
	}
	t = GetNextToken();

	if (t.tp == SYMBOL && strcmp(t.lx, "(") == 0)
	{
	}
	//t = PeekNextToken(); //unnecessary
	st2 = expressionList1();
	if (st2.ef != none1)
	{
		return st2;
	}

	t = GetNextToken();

	if (t.tp == SYMBOL && strcmp(t.lx, ")") == 0)
	{
		st.ef = none1;
		return st;
	}
}

SymbolTable expressionList1()
{
	SymbolTable st;
	Token t;
	t = PeekNextToken();
	if (strcmp(t.lx, ")") == 0)
	{
		
	}

	st2 = expression1();
	if (st2.ef != none1)
	{
		return st2;
	}

	t = PeekNextToken();
	
	if (strcmp(t.lx, ",")==0)
	{
		while (strcmp(t.lx, ",") == 0 && t.tp != EOFile)
		{
			t = GetNextToken();
			
			st2 = expression1();
            if (st2.ef != none1)
	{
		return st2;
	}

			t = PeekNextToken();
		}
		if (t.tp == EOFile)
		{
            st.ef = none1;
			return st;
		}
	}
	if (strcmp(t.lx, ")") == 0)
	{

	}

}

SymbolTable returnStatement1()
{
	SymbolTable st;
	Token t;
	t = GetNextToken();

	if (t.tp == RESWORD && strcmp(t.lx, "return") == 0)
	{
	}
	t = PeekNextToken();
	if (strcmp(t.lx, ";") == 0)
	{
		//
		t = GetNextToken();
		st.ef = none1;
		return st;
	}
	else
	{
		st2 = expression1();
		if (st2.ef != none1)
		{
			return st2;
		}
	}
	t = GetNextToken();

	if (strcmp(t.lx, ";") == 0)
	{
		//
		st.ef = none1;
		return st;
	}
}








/* EXPRESSIONS GRAMMAR*/

SymbolTable expression1()
{
	SymbolTable st;
	Token t;

	st2 = relationalExpression1();

if (st2.ef != none1)
		{
			return st2;
		}
	t = PeekNextToken();

	while (t.tp != EOFile && (strcmp(t.lx, "|") == 0 || strcmp(t.lx, "&") == 0))
	{
		t = GetNextToken();

		st2 = relationalExpression1();
if (st2.ef != none1)
		{
			return st2;
		}
		t = PeekNextToken();
	}

	if (t.tp == EOFile)
	{
        st.ef = none1;
		return st;
	}
    return st;
}

SymbolTable relationalExpression1()
{
	SymbolTable st;
	Token t;
	//OMG t = PeekNextToken();

	st2 = ArithmeticExpression1();
if (st2.ef != none1)
		{
			return st2;
		}

	t = PeekNextToken();

	while (t.tp != EOFile && t.tp == SYMBOL && (strcmp(t.lx, "=") == 0 || strcmp(t.lx, ">") == 0 || strcmp(t.lx, "<") == 0))
	{
		t = GetNextToken();
		st2 = ArithmeticExpression1();
		if (st2.ef != none1)
		{
			return st2;
		}
		t = PeekNextToken();
	}

	if (t.tp == EOFile)
	{
        st.ef = none1;
		return st;
	}
	return st;
}

SymbolTable ArithmeticExpression1()
{
	SymbolTable st;
	Token t;


	st2 = term1();


	t = PeekNextToken();

	while (t.tp != EOFile && t.tp == SYMBOL && (strcmp(t.lx, "+") == 0 || strcmp(t.lx, "-") == 0))
	{
		t = GetNextToken();
		st2 = term1();
if (st2.ef != none1)
		{
			return st2;
		}
		t = PeekNextToken();
	}

	if (t.tp == EOFile)
	{
		st.ef = none1;
		return st;
	}	

	st2 = factor1();
if (st2.ef != none1)
		{
			return st2;
		}
	t = PeekNextToken();

	while (t.tp != EOFile && t.tp == SYMBOL && (strcmp(t.lx, "*") == 0 || strcmp(t.lx, "/") == 0))
	{
		t = GetNextToken();
		st2 = factor1();

		if (st2.ef != none1)
		{
			return st2;
		}
		t = PeekNextToken();
	}

	if (t.tp == EOFile)
	{
		st.ef = none1;
		return st;
	}
    
    
	return st;
}

SymbolTable term1()
{

 SymbolTable st;
 Token t;

 st2 = factor1();
if (st2.ef != none1)
		{
			return st2;
		}
 t = PeekNextToken();

 while (t.tp != EOFile && t.tp == SYMBOL && (strcmp(t.lx, "*") == 0 || strcmp(t.lx, "/") == 0))
 {
 t = GetNextToken();
 st2 = factor1();
if (st2.ef != none1)
		{
			return st2;
		}
 t = PeekNextToken();
 }

 if (t.tp == EOFile)
 {
    st.ef = none1;
return st;
 }
 return st;
}







SymbolTable factor1()
{
	
	SymbolTable st;
	Token t;


	t = PeekNextToken();
	if ((t.tp == SYMBOL) && ((strcmp(t.lx, "-") == 0) || (strcmp(t.lx, "~") == 0)))
		{

			t = GetNextToken();
            //we get the thing if its there
        }
		
		st2 = operand1();
        if(st2.ef!=none1)
        {
            return st2;
        }
		return st;
	}





SymbolTable operand1()
{

	SymbolTable st;
	Token t;


	t = PeekNextToken();


	if (t.tp == INT)
	{
		
		t = GetNextToken();
		return st;
	}
	else if (t.tp == ID)
	{
		
		t = GetNextToken();
		
		t = PeekNextToken();
		

		if (t.tp == SYMBOL && strcmp(t.lx, ".") == 0)
		{
                //decimals?

			// just getting the dot
			t = GetNextToken();
			
			// now getting the thing after the dot
			t = GetNextToken();
			
		}

		t = PeekNextToken();


			if (strcmp(t.lx, "[") == 0)
			{

				t = GetNextToken();
				st2 = expression1();
if (st2.ef != none1)
		{
			return st2;
		}

				t = GetNextToken();

				if (t.tp == SYMBOL && strcmp(t.lx, "]") == 0)
				{

				}
			}

			else if (strcmp(t.lx, "(") == 0)
			{
				t = GetNextToken();
				st2 = expressionList1();
                if (st2.ef != none1)
		{
			return st2;
		}

				
				t = GetNextToken();

				if (t.tp == SYMBOL && strcmp(t.lx, ")") == 0)
				{
                    return st;
				}
                
				
			}
			
		}else if (strcmp(t.lx, "(") == 0)
			{
				
				t = GetNextToken();
				st2 = expression1();
if (st2.ef != none1)
		{
			return st2;
		}
				t = GetNextToken();

				if (strcmp(t.lx, ")") == 0)
				{
					
					return st;
				}
				else
				{
					return st;
				}
			}
		

		else if (t.tp == STRING)
		{
			t = GetNextToken();
			return st;
		}
		else if (strcmp(t.lx, "true") == 0)
		{
			t = GetNextToken();
			return st;
		}
		else if (strcmp(t.lx, "false") == 0)
		{
			t = GetNextToken();
			return st;
		}
		else if (strcmp(t.lx, "null") == 0)
		{
			t = GetNextToken();
			return st;
		}
		else if (strcmp(t.lx, "this") == 0)
		{
			t = GetNextToken();
			return st;
		}
            return st;
        
	}














































//parser parts end
//////////////////////////////////////////////////////////////////////






























































int InitSymbolTable(char* file_name)
{
    return InitLexer(file_name);
}


SymbolTable generate()
{
    SymbolTable st;
    
    st = class1();
    
    return st;
}

**/






#ifndef TEST_SYMBOLTABLE
/**
int main()
{

printf("\nSymbol Table Generation\n");

Token t;

//////
setbuf(stdout, NULL);
ParserInfo pi;

InitSymbolTable("Array.jack");

pi = Parse();
SymbolTable st;
st = generate();

//  if(pi.er == none)
//  {
//      //need to have no errors from the parser
//  }
////// we parse the code first
if(st.ef ==none1)
{
for(int a = 0; a<INDEX; a++)
{
    
    printf("Symbol: %s", symbolsfound[a]);
    printf("Line: %i",symbolline[a]);
    printf("Type: %s",symboltype[a]);
    printf("Symbol: %c\n",sorf[a]);
}
}
else
{
    printf("ERROR");
}
return 0;
    
}
**/

#endif














