#include<iostream>
using namespace std;


//Right half pyramid
// enter n : 5
// * 
// * * 
// * * * 
// * * * * 
// * * * * * 

void RHalfPyr(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << "*" << " ";
        }
        cout << "\n";
    }

}

//Inverted right half pyramid
// * * * * * 
// * * * *
// * * *
// * *
// *

void InRHalfPyr(int n){
    for (int i=1; i<=n; i++){
        for (int j=n+1-i; j>0; j--){
            cout << "*" << " ";
        }
        cout << endl;
    }
}

//half pyramid numbers
// enter n : 5
// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 
// 1 2 3 4 5 


void HalfPyrNum(int n){
    for (int i =1; i<=n; i++){
        for (int j=1; j<=i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

// print character right half pyramid
// enter n:5
// A 
// B C 
// D E F 
// G H I J 
// K L M N O 

void CharPyr(int n){
    char ch = 'A';
    for (int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << ch++ << " ";

        }
        cout << endl;
    }
}

//floyd's pattern
// enter n : 5
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15


void printFloyd(int n){
    int num=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << num++ << " ";
        }
        cout << endl;
    }
}

//left half Pyramid
// enter n : 5
//     *
//    **
//   ***
//  ****
// *****

void leftHalfPyr(int n){
    for (int i=1; i<=n; i++){
        for (int j=n+1-i; j>1; j--){
            cout <<" ";
        }
        for(int k=1; k<=i; k++){
            cout << "*" ;

        }
        cout << endl;

    }
}

//inverterd left half pyramid
// enter n : 5
// *****
//  ****
//   ***
//    **
//     *

void InvLeftHalfPyr(int n){
    for (int i=1; i<=n; i++){
        for(int k=1; k<i; k++){
            cout << " ";
        }
        for(int j=n+1-i; j>=1; j--){
            cout << "*" ;
        }
        cout << endl;
    }
}

//Pyramid
// enter n : 5
//     * 
//    * * 
//   * * * 
//  * * * *
// * * * * *

void printPyr(int n){
    for(int i=1; i<=n; i++){
        for(int j=n+1-i; j>1; j--){
            cout << " ";

        }
        for(int k=1; k<=i; k++){
            cout << "*" <<" ";
        }
       cout << endl;
    }
}

//inverted pyramid
// enter n:5
// * * * * * 
//  * * * *
//   * * *
//    * *
//     *

void invertPyr(int n){
    for(int i=1; i<=n; i++){
        for(int k=1; k<i; k++){
            cout << " ";
        }
        for(int j=n+1-i; j>=1; j--){
            cout << "*" << " ";
        }
        
        cout << endl;
    }

}

//Diamond Pattern
// Enter n : 5
//     * 
//    * * 
//   * * * 
//  * * * * 
// * * * * * 
// * * * * * 
//  * * * * 
//   * * * 
//    * * 
//     * 

void printDiamond(int n){

    //upper half
    for(int i=1; i<=n; i++){
        for(int j=n+1-i; j>1; j--){ // equlity not at 1 since we want n-1 times sp
            cout << " ";
        }
        for(int k=1; k<=i; k++){
            cout << "*" << " ";
        }
        cout << endl;
    }

    //lower half
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            cout << " ";
        }
        for(int k=n+1-i; k>=1; k--){//equality at 1 since we want n times *sp pair
            cout << "*" << " ";

        }
        cout <<endl;
    }
}

// hollow pyramid
// Enter n : 5
//     *
//    * *
//   *   *
//  *     *
// *********

void holPyr(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<n+1-i; j++){
            cout << " ";
        }

        cout << "*";
        for(int k=1; k<=2*(i-1)-2; k++){
            if(i==n){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        if(i!=1){
            cout << "*";
        }
        
        cout << endl;
    }
}

//HollowRectangle
// enter n : 5
// *****
// *   *
// *   *
// *   *
// *****

void printHolRec(int n){
    for(int i=1; i<=n; i++){
        cout << "*";
        for(int k=1; k<=n-2; k++){
            if(i==1 || i==n){
                cout << "*" ;
            }
            else{
                cout << " " ;
            }
        }
        cout << "*";
        cout << endl;
    }
}

//Butterfly
// enter n : 5
// *        *
// **      **
// ***    ***
// ****  ****
// **********
// **********
// ****  ****
// ***    ***
// **      **
// *        *

void printButterfly(int n){
    //upperhalf
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << "*" ;
        }
        for(int k=1; k<=2*(n-i); k++){
            cout << " " ;
        }
        for(int l=1; l<=i; l++){
            cout << "*" ;
        }
        cout << endl;
    }

    //lower half

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n+1-i; j++){
            cout << "*" ;
        }
        for(int k=1; k<=2*(i-1); k++){
            cout << " ";
        }
        for(int l=1; l<=n+1-i; l++){
            cout << "*" ;
        }
        cout << endl;
    }

}



int main(){
    int n;
    cout << "enter n : ";
    cin >> n;

    cout << "Right half Pyramid : \n"; 
    RHalfPyr(n);

    cout << "\nRight half Pyramid of numbers: \n";
    HalfPyrNum(n);

    cout << "\nRight half Pyramid of Chars : \n";
    CharPyr(n);

    cout << "\nFloyd Pattern : \n";
    printFloyd(n);

    cout << "\nInverted Right half Pyr : \n";
    InRHalfPyr(n);

    cout << "\nLeft Half pyramid : \n";
    leftHalfPyr(n);

    cout << "\nInverted Left Half Pyramid :\n";
    InvLeftHalfPyr(n);

    cout << "\nPyramid : \n";
    printPyr(n);

    cout << "\nInverted Pyramid : \n";
    invertPyr(n);

    cout << "\n Diamond Pattern : \n";
    printDiamond(n);

    cout << "\nHollow Pyramid :\n";
    holPyr(n);

    cout << "\nHollow Rectangle : \n";
    printHolRec(n);

    cout << "\nButterfly Pattern : \n";
    printButterfly(n);

    


    return 0;
}