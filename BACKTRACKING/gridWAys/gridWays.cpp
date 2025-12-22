#include<iostream>
using namespace std;

int gridways(int r, int c, int n, int m){
    if(r==n-1 && c == m-1){ // reched dest..BC
        return 1;
    }

    if(r>=n || c>=m){ // reached row end or col end cant. go further down or right resp. so 0 ways , therefore return 0;
// refer expl. below......
        return 0;
    }

    //right cell 
    int v1= gridways(r, c+1, n, m);
    //down cell
    int v2 = gridways(r+1, c, n, m);
    return v1+v2;
}

int main(){
    int r , c;
    cout << "enter rows;";
    cin >> r;
    cout << "enter cols:";
    cin >> c;
    cout << "number of gridways are : " << gridways(0,0, r, c);
    return 0;
}

// in the second bc , if you check for r>= n-1 || c>=m-1 that means you are returning 0 as soon as you reach the end 
//but you can go down from last col and right from last row
// so we should return 0 once we cross the last row or col
// that's why >=n || >=m