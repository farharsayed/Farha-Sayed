/************************************************************************
University of Leeds
School of Computing
COMP2932- Compiler Design and Construction
Lexer Module

I confirm that the following code has been developed and written by me and it is entirely the result of my own work.
I also confirm that I have not copied any parts of this program from another person or any other source or facilitated someone to copy this program from me.
I confirm that I will not publish the program online or share it with anyone without permission of the module leader.

Student Name: Farha Rashid Sayed
Student ID: 201548827
Email:  sc21frs@leeds.ac.uk
Date Work Commenced: 7/March/2023
*************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

// YOU CAN ADD YOUR OWN FUNCTIONS, DECLARATIONS AND VARIABLES HERE

// this is the final draft
//draft2 - in process of compiling
//(draft1 was not compiled)

#include <stdbool.h>

typedef enum TT
{
    keyword,
    id,
    num,
    sym,
    eof,
    err
} TokenTypes;

FILE *filename; // pointer to the file
char FILENAME[32];
const char *keywords[] = {"boolean", "char", "class", "constructor",
                          "do", "else", "false", "field", "function",
                          "if", "int", "let", "method", "null", "static",
                          "this", "true", "return", "var", "void", "while"};
int keywordd = 21;

const char symbols[] = {'(', ')', '{', '}', '[', ']', ',', ';', '=', '+', '-', '*', '/', '.', '&', '|', '~', '<', '>'};
int symbol = 19;

int line;

// IMPLEMENT THE FOLLOWING functions
//***********************************

// Initialise the lexer to read from source file
// file_name is the name of the source file
// This requires opening the file and making any necessary initialisations of the lexer
// If an error occurs, the function should return 0
// if everything goes well the function should return 1

int InitLexer(char *file_name)
{

    filename = fopen(file_name, "r");
    line = 1;
    if (filename == NULL)
    {
        printf("Error: cant open file\n");
        return 0; // indicating that there was an error
    }
    strcpy(FILENAME, file_name);

    return 1;
}

char ch;
// Get the next token from the source file
Token GetNextToken()
{
    Token t;
    // char arr[] = {};
    int a = 0; // temp
    char prevch;

    bool kw = false;
    bool com = false;

    ch = getc(filename);
    strcpy(t.fl, FILENAME);
    while (ch == '\0')
    {
        ch = getc(filename);
    }

    // adding line
    while (isspace(ch))
    {
        if (ch == '\n')
        {
            line = line + 1;
        }
        ch = getc(filename);
    }

    // if it is a comment
    while (ch == '/')
    {

        if (ch == '/')
        {

            ch = getc(filename);

            com = true;
            if (ch == '/')
            {

                while (ch != '\n')
                {
                    ch = getc(filename);
                }
                line = line + 1;
                com = false;
                ch = getc(filename);
            }

            else if (ch == '*')
            {
                com = true;
                while (ch != -1)
                {
                    if (ch == '\n')
                    {
                        line = line + 1;
                    }
                    if (prevch == '*' && ch == '/')
                    {
                        prevch = ch;
                        ch = getc(filename);
                        com = false;
                        break;
                    }
                    if (ch == EOF)
                    {
                        t.tp = ERR;
                        strcpy(t.lx, "Error: unexpected eof in comment");
                        t.ln = line;
                        t.ec = 0;
                        return t;
                    }
                    prevch = ch;
                    ch = getc(filename);
                }
                if (com == true)
                {
                    t.ln = line;
                    t.tp = ERR;

                    strcpy(t.lx, "Error: unexpected eof in comment");
                    t.ec = 0;
                    return t;
                }
            }

            else if (ch == EOF)
            {
                t.ln = line;
                t.tp = ERR;

                strcpy(t.lx, "Error: unexpected eof in comment");
                t.ec = 0;
                return t;
            }

            else
            {

                ungetc(ch, filename);

                t.tp = SYMBOL;
                t.ln = line;
                strcpy(t.lx, "/");
                return t;
            }
        }
        while (isspace(ch))
        {
            if (ch == '\n')
            {
                line = line + 1;
            }
            ch = getc(filename);
        }
    }

    if (ch == EOF)
    {

        t.tp = EOFile;
        strcpy(t.lx, "End of File");
        t.ln = line;
        return t;
    }

    // for white spaces in general

    while (isspace(ch)) // ignoring whitespaces until we find the first non-whitespace character
    {
        while (ch == '\n')
        {
            line = line + 1;
        }

        ch = getc(filename);
    }

    // checking for id
    if ((isalpha(ch)) || ch == '_')
    {
        a = 0;

        while (isalpha(ch) || ch == '_' || isdigit(ch))
        {

            t.lx[a] = ch;
            a = a + 1;
            ch = getc(filename);
        }
        t.lx[a] = '\0';

        ungetc(ch, filename);
        // checking for keywords
        kw = false;

        for (int b = 0; b < keywordd; b++)
        {
            if (strcmp(t.lx, keywords[b]) == 0)
            {

                t.tp = RESWORD;
                t.ln = line;

                kw = true;
                return t;
            }
        }
        if (kw == false)
        {
            t.tp = ID;
            t.ln = line;
            return t;
        }
    }

    // STRING LITERAL
    if (ch == '"')
    {

        a = 0;

        ch = getc(filename);
        while (ch != '"')
        {
            if (ch == '\n')
            {
                strcpy(t.lx, "Error: new line in string constant");
                t.tp = ERR;
                t.ec = 1;
                t.ln = line;
                return t;
            }
            if (ch == EOF)
            {
                strcpy(t.lx, "Error: unexpected eof in string constant");
                t.tp = ERR;
                t.ec = 2;
                t.ln = line;
                return t;
            }

            t.lx[a] = ch;
            a++;
            ch = getc(filename);
        }

        t.tp = STRING;
        t.lx[a] = '\0';
        t.ln = line;
        return t;
    }
    if (isdigit(ch))
    {
        a = 0;

        while (isdigit(ch))
        {
            t.lx[a] = ch;
            a = a + 1;
            ch = getc(filename);
        }

        t.lx[a] = '\0';

        ungetc(ch, filename);
        t.ln = line;
        t.tp = INT;
        return t;
    }

    for (int b = 0; b < symbol; b++)
    {
        if (ch == symbols[b])
        {
            t.lx[0] = ch;
            t.lx[1] = '\0';

            t.tp = SYMBOL;
            t.ln = line;
            return t;
        }
    }

    // if nothing else its illegal symbol:
    strcpy(t.lx, "Error: illegal symbol in source file");
    t.tp = ERR;

    t.ln = line;
    t.ec = 3;
    return t;
}
// peek (look) at the next token in the source file without removing it from the stream
Token PeekNextToken() 
{

    Token t;
    int marker;
    marker = ftell(filename);
    int prevmarker = line;
    t = GetNextToken();
    line = prevmarker;
    fseek(filename, marker, SEEK_SET);
    return t;
}

// clean out at end, e.g. close files, free memory, ... etc
int StopLexer()
{
    if (filename == NULL)
        return 0;

    fclose(filename);
    filename = NULL;

    return 1;
}

// do not remove the next line
#ifndef TEST

// the following is just for ease in testing done in the main function
char *TokenTypeString(TokenType t)
{
    if (t == RESWORD)
        return "RESWORD";
    else if (t == ID)
        return "ID";
    else if (t == INT)
        return "INT";
    else if (t == SYMBOL)
        return "SYMBOL";
    else if (t == STRING)
        return "STRING";
    else if (t == ERR)
        return "ERR";
    else if (t == EOFile)
        return "EOFile";
    else
        return "Not a token type";
}

//testing main for random files
int main()
{
    setbuf(stdout, NULL);

    Token t;
    char *filenameis = "IntegersOnly.jack"; // testing for this file

    InitLexer(filenameis);

    while (t.tp != EOFile && t.tp != ERR)
    {
        t = GetNextToken();

        printf("< %s, %i, %s, %s >\n", t.fl, t.ln, t.lx, TokenTypeString(t.tp));
    }
    if (t.tp == ERR)
    {
        printf("< %s, %i, %s, %s >\n", t.fl, t.ln, t.lx, TokenTypeString(t.tp));
    }
    return 0;
}
// do not remove the next line
#endif