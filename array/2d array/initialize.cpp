#include <iostream>
using namespace std;

int main () {
    int students[3][3] = {{100,100,100},
                          {85,74,89},
                          {63,72,65}}; //in declaration we write number of rows that starts from 1 but when we call an element we write its row index and column index which starts from 0 !!!


    cout << students[0][0] << endl;
    cout << students[0][1] << endl;
    cout << students[0][2] << endl;
    cout << students[1][0] << endl;
    cout << students[1][1] << endl;
    cout << students[1][2] << endl;
    cout << students[2][0] << endl;
    cout << students[2][1] << endl;
    cout << students[2][2] << endl;





    
                          
    return 0;
}