#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<char>> board){
    int n = board.size();
    int static count =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------\n";
    cout << "count of boards :" << ++count << endl;
    cout << "---------------------\n";
}

bool isSafe(vector<vector<char>> board, int row, int col){
    int n = board.size();
    // only diagonal safety needed to be checked
    // diagonal left
    for(int i=row, j=col; i>=0 && j<n; i--, j++){
        if(board[i][j]=='B'){
            return false;
        }
    }

    //diagonal right
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j]=='B'){
            return false;
        }
    }
    
    return true; // when d safe

}

void nBishops(vector<vector<char>> board, int row){
    int n = board.size();
    if(row==n){
        printBoard(board);
        return; 
    }
   
    for(int j=0; j<n; j++){// cols
        if(isSafe(board, row, j)){
            board[row][j]='B'; // place the b when safe
            nBishops(board, row+1); // rec call for next row
            board[row][j]='.'; //backtracking , replace by .
        }
    }
}


int main(){
    vector<vector<char>> board;
    int n;
    cout << "Enter n : ";
    cin >> n;
    for(int i=0; i<n; i++){
        vector<char> newRow;
        for(int j=0; j<n; j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    nBishops(board, 0);
    return 0;
}