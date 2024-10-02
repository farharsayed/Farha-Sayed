

// ********************************************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "tic.h"

// use this 2d array to store the moves of the game, please don't change its name or size
char grid[MaxGrid][MaxGrid]; // this is the grid that will be used to store the moves of the game

int __Check_Count; // do not use this variable, it is for the grader only


// please use this function to prompt the user to enter the grid size to start a new game
void promptEnterGridSize ()
{
  printf ("Enter grid size (3-10):");
}

// please use this function to prompt the user to enter the winning length for the new game
// the parameter represents the maximum winning length for this game
void promptEnterWinLength (int max_win_length)
{
  printf ("Enter winning length (3-%i):", max_win_length);
}

// please use this function to prompt the user to enter the location of the symbol
// this function takes as a parameter the symbol of the player to be prompted
void promptChooseLocation (char symbol)
{
  printf ("Player %c, Choose Location (row,col): ", symbol);
}

// please use this function to show an error message when an index is out of range
void showErrIndex ()
{
  printf ("Index out of range, please re-enter\n");
}

// please use this function to show an error message when a location is already taken
void showErrTaken ()
{
  printf ("This location is already taken\n");
}

// please use this function to show the win message at the end of the game
// this function takes as parameter the symbol of the player who won the game
void showWinMessage (char symbol)
{
  printf ("**************************\n");
  printf ("Player %c has won the game\n", symbol);
  printf ("**************************\n");
}

// please use this function to show a game over (draw) message at the end of the game
void showGameOverMessage ()
{
  printf ("Game over; there are no winners\n");
}

//  please use this function to prompt the user to choose if they want to play back the game (at the end of the game)
void promptPlayBackGame ()
{
  printf ("\nWould you like to play back the recorded game? (y,n)?");
}

// please use this function to prompt the user to answer with n (next) or e (exit)
// to indicate if they want to proceed with the game's replay or exit the program
void promptNextOrExit ()
{
  printf ("Next or Exit (n,e)?");
}

// You will use this function in effPlayerHasWon (see below).
// This function is basically a wrapper around an if statement to compare the content of the cell at row,col with symbol
// However, it also counts the number of times the function is called
// Needless to say again, don't change this function
int check (int row, int col, char symbol)
{
  __Check_Count++;
  if (grid[row][col] == symbol)
    return 1;
  return 0;
}

// Used by the grader to peek at a certain cell in the grid. Don't use this function
int peek (int row, int col)
{
  return grid[row][col];
}


// ************************************************

int gs = 0;
int ar = 0;



// END OF SECTION FOR DECLARRING ADDITIONAL GLOBAL VARIABLES
// ----------------------------------------------------------

// -------------------------------------------------------------------------------------------------

// The purpose of this function is to to start a new game
// It is used to initialise everything at the start of a new game
// This functions takes two integer parameters:
// The first parameter (gridsize) represents the size of the grid of the new game, .e.g. 3 for 3x3 game
// The minimum size of the grid is 3 and the maximum size is 10, if the value of the parameter is wrong (less than 3 or > 10)
// the function returns 0 indicating failure to start a new game.
// The second parameter (winlength) is the number of consecutive symbols for the winning case.
// This number cannot be less than 3 or > gridsize (why?), think but don't click :-)
// If the value of the second parameter is invalid (<3 or >gridsize) the function returns 0 (failure)
// If everything is correct the function returns 1 indicating success in initialising the game.
int newGame (int gridsize, int winlength)
{
  //checking if gridsize is within appropriate bounds
  if(gridsize<3 || gridsize>10)
    {
      printf("Gridsize must be between 3 and 10");
      printf("Failure to start a new game");
    return 0;
    }
  //checking whether winning length is within appropriate bounds
  if(winlength<3 || winlength>gridsize)
    {
      printf("The winning length must be between 3 and 10");
      printf("Failure to start a new game");
      return 0;
    }
  return 1;
}

// The purpose of this function is to show the game's grid on the screen
// The grid should exactly look like the examples in the assignment specification
// Please note the following when you implement the function:
// There is one empty line before the grid to make it stand out from text before it
// The column indices are printed at the top and the first one is indented by exactly one tab (\t); indices are separated by exactly one space
// The row indices are printed at the left followed by exactly one tab (\t)
// The grid symbols are separated by exactly one space
// There is one empty line after the grid to make it stand out from text after it
void showGrid ()
  {
    printf("\n");
    printf("\t");
    for(int j = 0; j< gs; j++)
      {
        printf("%i ", j);
      }
      printf("\n\n");
      for(int a1 = 0; a1<gs; a1++)
        {
          printf("%i\t",a1);
          for(int b1 = 0; b1<gs; b1++)
          {
            printf("%c ",grid[a1][b1]);
          }
          printf("\n");
        }
    printf("\n");
  }

// The purpose of this function is to make a move by a player.
// Making a move means putting the player's symbol (letter) in the desired cell
// This function takes 3 parameters. The first two represent indices of the row and column of the cell in which the player
// wants to place their symbol.
// The last parameter is the symbol (letter) of that player.
// A move can only be made if:
// 1- The row and column numbers are valid (not less than 0 or greater than the game's grid size), and
// 2- the cell is not already occupied by another symbol, and
// 3- the symbol is a valid one (X or O).
// If the move can be made (because it is valid), the function makes the move (i.e. puts the symbol in the cell) and returns 1 indicating success.
// otherwise the function returns 0 indicating failure to make the move
// my solution is 4 lines only
int makeMove(int row, int col, char symbol)
  {
    if (row>=0&&row<gs&&col>=0&&col<gs&&grid[row][col]=='.'&&(symbol=='X'||symbol=='O'))
      {
        grid[row][col] = symbol;
        return 1;
      }
      else
      return 0;
  }

// This function is used to check if the board is full, i.e. every location in the grid is filled with either X or O
// it returns 1 if the grid is full, 0 otherwise
// my solution is 5 lines
int boardIsFull()
  {
    int bif = 0;
    for(int a2 = 0; a2<gs; a2++)
    {
      for(int b2 = 0; b2<gs; b2++)
      {
        if(grid[a2][b2] == '.')
        {
          bif = 1;
          a2 = gs, b2 = gs;
          return 0;
        }
      }
    }
    if(bif ==0)
    return 1;
  }


// This function is used to check if there is any horizontal line in the grid that contains a consecutive sequence of the same symbol
// It can be used to check that a player has won the game by forming a horizontal run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed a horizontal line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating failure to make a move
int checkHorizontal (char symbol, int length)
  {
    if((symbol!='X' && symbol!='O') ||length<3 || length>gs)
    return -1;
    int count = 0;
     for(int a3 = 0; a3<gs; a3++)
      {
        for(int b3 = 0; b3<gs; b3++)
          {
            if(grid[a3][b3] == symbol)
              {
                count++;
                if(count == length)
                return 1;
              }
            if(grid[a3][b3] != symbol)
            count = 0;
          }
        }
        if(count!=length)
    return 0;
  }


// This function is used to check if there is any vertical line in the grid that contains a consecutive sequence of the same symbol
// It can be used to check that a player has won the game by forming a vertical run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed a vertical line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating failure to make a move
int checkVertical (char symbol, int length)
  {
    if((symbol!='X' && symbol!='O')||length<3 || length>gs)
    return -1;
    int count = 0;
     for(int a4 = 0; a4<gs; a4++)
     {
       for(int b4= 0; b4<gs; b4++)
       {
         if(grid[b4][a4] == symbol)
         {
           count++;
           if(count == length)
           return 1;
         }
         if(grid[a4][b4] != symbol)
         count = 0;
       }
     }
     if(count!=length)
     return 0;
  }

// This function is used to check if there is any diagonal line in the grid that contains a consecutive sequence of the same symbol
// A diagonal line runs from higher left to lower right (or vice versa). Note that there are more than one diagonal line in a grid.
// It can be used to check that a player has won the game by forming a diagonal run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed a diagonal line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating failure to make a move
int checkDiagonals (char symbol, int length)
  {
    if((symbol!='X' && symbol!='O')||length<3 || length>gs)
    return -1;
    int count = 0;
    int a5 = 0;
    for(int b5 = 0; b5<gs; b5++)
    {
      while(count<length)
      {
        a5 = 0;
        while(a5<MaxGrid)
        {
          if(grid[a5][b5] == symbol)
          {
          count++;
          if(count == length)
          return 1;
          }
          if(grid[a5][b5] != symbol)
          count = 0;
          a5++;
        }
        if(count == length)
        return 1;
      }
    }
    if(count!=length)
    return 0;
}


// This function is used to check if there is any anti-diagonal (reverse diagonal) section in the grid that contains a consecutive sequence of the same symbol
// An anti-diagonal line runs from higher right to lower left (or vice versa). Note that there are more than one anti-diagonal line in a grid.
// It can be used to check that a player has won the game by forming an anti-diagonal run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed an anti-diagonal line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating an failure to make a move
int checkAntiDiagonals (char symbol, int length)  //based on attempt 4
{
  if((symbol!='X' && symbol!='O')||length<0 || length>MaxGrid)
  return -1;
  int count = 0;
  int a6 = 0;
  for(int b6 = gs-1; b6>=0; b6--)
  {
    while(count<length)
    {
    a6 = 0;
    while(a6<gs)
    {
      if(grid[a6][b6] == symbol)
      {
      count++;
      if(count == length)
      return 1;
    }
      if(grid[a6][b6] != symbol)
      count = 0;
      a6++;
    }
    if(count == length)
    return 1;
    }
  }
  if(count!= length)
return 0;
}


// This function is used to check if a player has won the game by forming a horizontal, vertical, diagonal, or anti-diagonal line
// of the required length. This function should use the above four functions (checkHorizontal, checkVertical, checkDiagonals, and checkAntiDiagonals)
// to determine if the player has one
// The function returns 1 if the player given by symbol has won, and 0 if the player has not won
// If any of the parameters is invalid the function returns -1 indicating failure to check
// my solution is 5 lines
int playerHasWon (char symbol , int length)
{
    int p = checkHorizontal(symbol, length), q = checkVertical(symbol, length), r = checkDiagonals(symbol,length), s = checkAntiDiagonals(symbol,length);
    if((symbol!= 'X' && symbol!='O') || length<0||length>gs)
    return -1;
    if (p == 0 && q == 0 && r == 0 && s == 0)
    return 0;
    if (p == 1 || q == 1 || r == 1 || s == 1)
    return 1;
    else
    return -1;
}

// Do you think the above function (playerHasWon) is the most efficient way of detecting a win?
// Do we do this as humans when we play the game?
// The answer is NO.
// The purpose of this function is to implement a much more efficient version of the playerHasWon function
// The function takes four parameters.
// The first two parameters represent the location (row, and col) of the last move made
// by a player.
// The second parameter is the symbol of that player.
// The last parameter is the length of the winning line
// We will assess the efficiency of the function by the number of times we need to check the contents of a cell.
// To count the number of checks, I have prepared a function called check - see the top of this file - that you have
// to use instead of an if statement when you need to compare the contents of a cell to a given symbol.
//
// This function returns 1 if the player has formed a winning line immediately after placing their symbol in the
// cell given by row,col. If the player did not win, the function returns 0
// It returns -1 if any of the parameters have an invalid value.
int effPlayerHasWon (int row, int col, char symbol , int length)
{
  int u = 0, w = 0;
  if(row<0||row>gs||col<0||col>gs||length<3||length>gs)
  return -1;
  int f = 0; //check variable
  int count = 0;
  int ch = 0; // count horizontal
  int cv = 0; //count vertical
  int cd = 0; //count diagonal
  int cad = 0; //count antidiagonal


//checking horizontal
for(int m = 0; m<gs; m++)
  {
    if(check(row,m,symbol)==1)
      {
        ch++;
          if(ch == length)
          return 1;
        }
    else
    ch = 0;
}

//checking vertical
for(int n = 0; n<gs; n++)
{
  if(check(n,col,symbol)==1)
    {
        cv++;
        if(cv == length)
        return 1;
      }
  else
  cv = 0;
}

//checking diagonals
int var = row, vac = col; //var to check rows for diagonal, vac to check columns for diagonal
while(var>=0&&vac>=0)
{
var--;
vac--;
}

while(var<gs&&vac<gs)
{
if(check(var,vac,symbol)==1)
cd++;
else
cd = 0;
var++;
vac++;
if(cd==length)
return 1;
}


//checking antidiagonals


int varad = row, vacad = col; //varad to check rows for antidiagonal, varad to check columns for antidiagonal
while(varad>=0&&vacad<gs)
{
varad--;
vacad++;
}

while(varad<gs&&vacad>=0)
{
if(check(varad,vacad,symbol)==1)
cad++;
else
cad = 0;
varad++;
vacad--;
if(cad==length)
return 1;
}


if(cv ==length || ch == length|| cd == length|| cad == length)
return 1;
else
return 0;
}
//----------------------------------------------------------------------

void startinggrid()
{
  for(int ol = 0; ol<gs;ol++)
  {
    for(int il = 0; il<gs; il++)
    {
      grid[ol][il]='.';
    }
  }
}

void playback(int arow[],int acol[], int wo)
{
  char noe; //nextorexit
  startinggrid();
  showGrid();
  promptNextOrExit();
  scanf(" %c", &noe);
  if(noe == 'e')
  exit(0);
    for(int arr = 0; arr<=ar; arr++)
    {
        if(arr%2 == 0)
        {
          makeMove(arow[arr],acol[arr],'X');
        }
        if(arr%2 == 1)
        {
          makeMove(arow[arr],acol[arr],'O');
        }
        showGrid();
        if((boardIsFull()==1 )&&(wo==0))
        {
          exit(0);
        }
        else{
        if(arr+1<=ar)
          {
            promptNextOrExit();
            scanf(" %c", &noe);
            if(noe == 'e')
            exit(0);
          }
      }
    }
}

#ifndef TEST
int  main (int argc, char* argv[])
{
  int wl = 0; //variables to accept grid size and winning length
  gs = 0;//gridsize
  char symb;
  int mm = 0;//makemove
  int game =-1;
  int rowe = 0;
  int cole= 0;//rowe and cole to store row and col
  int g = 0; //to check if position is available
  int win = 0; //to end game if a player has won
int ephw = 0;//effplayerhaswon

  do
  {
    gs = 0; wl = 0;
    promptEnterGridSize();
    scanf("%i",&gs);
    promptEnterWinLength(gs);
    scanf("%i",&wl);
    newGame(gs,wl);

  }while(gs<3||gs>10||wl<3||wl>gs);

  startinggrid();//to initialise grid with all '.'
int arrow[gs*gs],arcol[gs*gs];//to assist with playback
ar = -1;

  while((game<(gs*gs)) && win == 0)
    {
      showGrid();
      game++;
      g = 0;
    if(game%2 == 0)
      symb = 'X';
    if(game%2 == 1)
      symb = 'O';
      do {
        ar++;
        g = 1;
        promptChooseLocation(symb);
        scanf("%i,%i" ,&rowe , &cole );
        arrow[ar] = rowe;
        arcol[ar] = cole;
        if(grid[rowe][cole]=='X'||grid[rowe][cole]=='O')
          {
            g = 0;
            ar--;
            showErrTaken();
          }
        if(rowe<0||cole<0||rowe>=gs||cole>=gs)
          {
            g = 0;
            ar--;
            showErrIndex();
          }
      }while(g==0);
      mm = makeMove(rowe,cole,symb);
      ephw = effPlayerHasWon(rowe,cole,symb,wl);
    if(ephw ==1)
      {
        showGrid();
        showWinMessage(symb);
        win = 1;
      }
    if((boardIsFull()==1 )&&(win==0))
      {
        showGrid();
        showGameOverMessage();
        break;
      }
}

char pbg; //to accept play back game
promptPlayBackGame();
scanf(" %c", &pbg);
if(pbg =='y')
playback(arrow,arcol,win);
else
exit(0);



  return 0;
}
#endif
  
