#include <iostream>

using namespace std;

void printBoard(char (&board)[3][3]);

int main(){
  char board[3][3];
  //Initialize empty board:
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      board[i][j] = ' ';
    }
  }
  board[2][2] = 'X';
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
