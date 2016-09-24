#include <iostream>
#include <ctype.h>

using namespace std;

void printBoard(char (&board)[3][3]);
bool fullBoard(char (&board)[3][3]);

int main(){
  cout << "Enter moves in the format <row><column> (for example, \"b3\".)" << endl;
  cout << "Enter \"q\" to quit at any time." << endl;
  char board[3][3];
  char turn = 'X';
  char input[3];
  
  //Initialize empty board:
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      board[i][j] = ' ';
    }
  }

  while(!fullBoard(board)){//Single game here
    printBoard(board);
    cout << turn << "\'s turn. Enter move:";
    cin >> input;
    cout << endl;
    if(input[0] == 'q'){
      break;
    }
    board[tolower(input[0]) - 'a'][input[1]-'1'] = turn;
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
