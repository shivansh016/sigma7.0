#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<char>> board){
    int n = board.size();
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----\n";
}

void nQueens(vector<vector<char>> board, int row){
    int n = board.size();
    if(row==n){
        printBoard(board);
        return;
    }
    for(int j=0; j<n; j++){
        board[row][j]='Q'; // replace the Q at the jth position
        nQueens(board, row+1); // recursive call for next row of board
        board[row][j]='.'; // again change the Q to '.' while backtracking
    }
}

int main(){
    vector<vector<char>> board;
    int n = 2;
    for(int i=0; i<n; i++){
        vector<char> newRow;
        for(int j=0; j<n; j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);

    }
    nQueens(board,0);
    return 0;
}