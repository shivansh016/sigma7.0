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
        if(board[row][j]=='R'){
            return false;
        }
    }

    // vertical safety
    for(int i=0; i<=row; i++){
        if(board[i][col]=='R'){
            return false;
        }
    }

  

    return true; // when v,h all safe
}

void nRooks(vector<vector<char>> board, int row){
    int n = board.size();
    if(row == n){
        printBoard(board);
        return;
    }

    for(int j=0; j<n; j++){
        if(isSafe(board, row, j)){
            board[row][j]='R'; // place the R
            nRooks(board, row+1); // rec call for next row
            board[row][j]='.'; // backtracking then remove the R and replace by '.'
        }

    }
    

}

int main(){
    vector<vector<char>> board;
    int n;
    cout << "enter n : (please enter a small value)";
    cin >> n;
    for(int i=0; i<n; i++){
        vector<char> newRow;
        for(int j=0; j<n; j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    nRooks(board,0);
    cout << "if nothing shown means n( or size) is invalid to place a R >>>> ignore if you see output ";
    return 0;
}