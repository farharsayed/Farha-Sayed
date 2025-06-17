#ifndef SYMBOLS_H
#define SYMBOLS_H

#include "lexer.h"
#include "parser.h"

// define your own types and function prototypes for the symbol table(s) module below

/*
typedef enum{

                //variable usage
    te,         //temp error type
    e1,         //variable given value without declaring type
    e2,         //variable used in expression without initializing its value
    e3,         //scope resolution -- maintaining static and field
                //type checking
    e4,         //RHS of assignment statement doesnt have same type as LHS
    e5,         //coercion -- converting one type to another failed
    e6,         //expressions in an array have wrong value
                //function calling
    e7,         //function called without declaration
    e8,         //function call has diff no. of parameters
    e9,         //function call has diff type/order of parameters
    e10,        //function returns incompatible value compared to itsreturn type
    e11,        //unreachable code -- theres a path of the function wherein theres no return value (ex: only one return statement and its inside an if)
    none1       //no error
    } ErrorsFound;

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

**/

// typedef struct 
// {
//    char sn[128]; //t.lx
//    char stt[128]; //t.tp?? maybe?
//    int sl; //t.ln
//    ErrorsFound ef;//from enum above
// } SymbolTable;

//int InitSymbolTable(char* file_name);
//SymbolTable generate();

//at leave 






 #endif
 