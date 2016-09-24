#include <iostream>
#include <ctype.h>

using namespace std;

void printBoard(char (&board)[3][3]);
bool fullBoard(char (&board)[3][3]);
bool checkWin(char(&board)[3][3], char player);
void clearBoard(char(&board)[3][3]);
bool restartGame(char (&board)[3][3], int xwins, int owins, int ties);

int main(){
  cout << "Enter moves in the format <row><column> (for example, \"b3\".)" << endl;
  cout << "Enter \"q\" to quit at any time." << endl;
  char board[3][3];
  char turn = 'X';
  char input[3];
  bool done = false;
  int owins = 0;
  int xwins = 0;
  int ties = 0;
  
  //Initialize empty board:
  clearBoard(board);

  while(true){//Primary loop
    printBoard(board);
    int i = -1;
    int j = -1;
    cout << turn << "\'s turn. Enter move:";
    //Get valid move
    while(true){
      cin >> input;
      cout << endl;
      if(input[0] == 'q'){
	cout << endl;
	cout << "gg";
	i = 'q';
	break;
      }
      i = tolower(input[0]) - 'a';
      j = input[1] - '1';
      if(i>=0 && i<3 && j>=0 && j<3 && board[i][j] == ' '){
	board[tolower(input[0]) - 'a'][input[1]-'1'] = turn;
	break;
      }
      else{
	cout << "Enter a valid move, you cheater." << endl;
      }
    }
    if(i == 'q'){
      break;
    }
    //Check wins
    if(checkWin(board, turn)){
      printBoard(board);
      cout << turn << " wins!" << endl;
      //Update scores
      if(turn == 'O'){
	owins++;
      }
      else{
	xwins++;
      }
      
      if(!restartGame(board, xwins, owins, ties)){
	break;
      }
    }
    //Check ties
    if(fullBoard(board)){
      cout << "Tie!" << endl;
      ties++;
      if(!restartGame(board, xwins, owins, ties)){
	break;
      }
    }
    //switch turns
    if(turn == 'X'){
      turn = 'O';
    }
    else{
      turn = 'X';
    }
  }
}


void printBoard(char (&board)[3][3]){
  cout << "  1 2 3" <<endl;
  for(int i=0; i<3; i++){//rows
    cout << (char)('A' + i) << " ";
    for(int j=0; j<3; j++){//columns
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

bool fullBoard(char (&board)[3][3]){
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if(board[i][j] == ' '){
	return false;
      }
    }
  }
  return true;
}

bool checkWin(char (&board)[3][3], char player){
  //Horizontals and verticals:
  for(int i=0; i<3; i++){
    if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
      return true;
    }
    if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
      return true;
    }
  }
  //Diagonals:
  //Seriously 3x3 is the threshold for deciding whether I should loop or manually check.
  if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
    return true;
  }
  if(board[2][0] == player && board[1][1] == player && board[0][2] == player){
    return true;
  }
  
  return false;
}

void clearBoard(char (&board)[3][3]){
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      board[i][j] = ' ';
    }
  }
}

bool restartGame(char (&board)[3][3], int xwins, int owins, int ties){
  //Displays stats.
  //Returns whether the user wants to play again.
  //Clears board if necessary.
  char ans[2];
  cout << endl;
  cout << "Stats: " << "X wins: " << xwins << "; O wins: " << owins << "; ties: " << ties << "." << endl;
  cout << "Play again? (y/n) ";
  cin >> ans;
  cout << endl;

  if(tolower(ans[0]) == 'y'){
    clearBoard(board);
    return true;
  }
  return false;
}
