#include <iostream>
#include <ctype.h>

using namespace std;

void printBoard(char (&board)[3][3]);
bool fullBoard(char (&board)[3][3]);
bool checkWin(char(&board)[3][3], char player);
int main(){
  cout << "Enter moves in the format <row><column> (for example, \"b3\".)" << endl;
  cout << "Enter \"q\" to quit at any time." << endl;
  char board[3][3];
  char turn = 'X';
  char input[3];
  bool win = false;
  
  //Initialize empty board:
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      board[i][j] = ' ';
    }
  }

  while(!fullBoard(board) && !win){//Single game here
    printBoard(board);
    cout << turn << "\'s turn. Enter move:";
    cin >> input;
    cout << endl;
    if(input[0] == 'q'){
      break;
    }
    board[tolower(input[0]) - 'a'][input[1]-'1'] = turn;
    win = checkWin(board, turn);
    //Switch turns
    if(turn == 'X'){
      turn = 'O';
    }
    else{
      turn = 'X';
    }
  }
  printBoard(board);
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
