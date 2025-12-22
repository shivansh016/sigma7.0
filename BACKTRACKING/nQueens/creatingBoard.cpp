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
    printBoard(board);
    return 0;
}