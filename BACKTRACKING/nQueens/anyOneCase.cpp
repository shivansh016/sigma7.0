#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<char>> board){
    int n = board.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";

        }
        cout << endl;
    }
    cout << "----------\n";
}

bool isSafe(vector<vector<char>> board, int row, int col){
    int n = board.size();
    // horizontal safety
    for(int j=0; j<n; j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }

    // vertical safety
    for(int i=0; i<=row; i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }

    // diagonal safety

    // diagonal left
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){ // as we move diagonally up in left row and col both decreases
        if(board[i][j]=='Q'){
            return false;
        }
    }
    // diagonal right
    for(int i=row, j=col; i>=0 && j<n; i--, j++){// as we move diagonally up in right row num decreases and col increases
        if(board[i][j]=='Q'){
            return false;
        }
    }

    return true; // when v,d,h all safe
}

bool nQueens(vector<vector<char>> board, int row){
    int n = board.size();
    if(row == n){
        printBoard(board);
        return true;
    }
    
    for(int j=0; j<n; j++){
        if(isSafe(board, row, j)){
            board[row][j]='Q'; // place the Q                
            if(nQueens(board, row+1)){
                return true; // immediately stop
            } // rec call for next row
            board[row][j]='.'; // backtracking then remove the Q and replace by .
        }

    }

    return false;
}

int main(){
    vector<vector<char>> board;
    int n;
    cout << "enter n : ";
    cin >> n;
    for(int i=0; i<n; i++){
        vector<char> newRow;
        for(int j=0; j<n; j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    int sol = nQueens(board,0);
    cout << "solutions :" << sol <<" , if u got 0 means no  solutions exist";
    
    return 0;
}