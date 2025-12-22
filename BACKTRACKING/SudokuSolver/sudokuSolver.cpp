#include<iostream>
using namespace std;

void printSudoku(int Sud[][9]){
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << Sud[i][j] << " ";
        }
        cout << endl;
    }

}

bool isSafe(int Sudoku[9][9], int row, int col, int dig){
    // vertical check
    for(int i = 0 ; i<9; i++){
        if(Sudoku[i][col] == dig){
            return false;
        }
    }

    // horizontal check
    for(int j=0; j<9; j++){
        if(Sudoku[row][j] == dig){
            return false;
        }
    }

    // 3*3 grid check
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;
    //for rows...division by 3 gives vertical grid number eg. 0to2/3 == 0 means first grid,, and then 0*3=0 i.e 1st row, 1*3=3 i.e 4th row, and so on...
    //        ...multiply by 3 gives horizontal grid number

    //similarly can be understood for col as well
    
    for(int i=startRow; i<=startRow+2; i++ ){
        for(int j=startCol; j<=startCol+2; j++){
            if(Sudoku[i][j] == dig){
                return false;
            }
        }
    }

    return true; // after checking for vertical, horizontal, and respective 3*3 grid 
}

bool SudokuSolver(int Sudoku[9][9], int row, int col){
    if(row == 9){ // sudoku solved
        printSudoku(Sudoku);
        return true;
    }

    //next cell ke liye call ka logic...
    int nextRow = row;//row to same rahegi
    int nextCol = col + 1;// col update by +1
    if(nextCol == 9){ // jab col last col ko cross kar jaye
        nextRow = row + 1; // update row by +1
        nextCol = 0; //col =0
    }
//filling of digits
    if(Sudoku[row][col] != 0){ //already filled
        return SudokuSolver(Sudoku, nextRow, nextCol);
    }

    for(int dig=1; dig<=9; dig++){ //when not filled
        if(isSafe(Sudoku, row, col, dig)){
            Sudoku[row][col] = dig; //place the digit when safe
            if(SudokuSolver(Sudoku, nextRow, nextCol)){ // next cell ke liye func call
                return true; //jab next cell true return karegi to function bhi true return karega...
            } 
            Sudoku[row][col]=0; //agar cell ke liye true nahi aaya to current cell me 0 fir se daal denge and try to store check for next dig value....
        }

    }

    return false; // jab for loop se koi bhi true na return ho, matlab saari digits ko place kara ke dekh liya aur ek bhi true na hui to Sudoku solver false return karega...



}

int main(){
    int Sudoku[9][9] = {{0, 0, 8, 0, 0, 0, 0, 0, 0},
                        {4, 9, 0, 1, 5, 7, 0, 0, 2},
                        {0, 0, 3, 0, 0, 4, 1, 9, 0},
                        {1, 8, 5, 0, 6, 0, 0, 2, 0},
                        {0, 0, 0, 0, 2, 0, 0, 6, 0},
                        {9, 6, 0, 4, 0, 5, 3, 0, 0},
                        {0, 3, 0, 0, 7, 2, 0, 0, 4},
                        {0, 4, 9, 0, 3, 0, 0, 5, 7},
                        {8, 2, 7, 0, 0, 9, 0, 1, 3}};
    
    cout << SudokuSolver(Sudoku, 0, 0);
    return 0;
    
}