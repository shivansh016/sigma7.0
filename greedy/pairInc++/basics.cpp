#include<iostream>
#include<utility>
using namespace std;
// always include utility library for pairs... even if it sometimes comes included with vectors and some others...
// syntax : pair<datatype_of_first_value, datatype_of_second_value> Name_of_pair = {val1, val2};
// syntax : pair<datatype_of_first_value, datatype_of_second_value> Name_of_pair (val1, val2);


// make_pair(); this function is used to make pair 
// syntax of make_pair()--> pair<_,_> pair_name = make_pair(first value, second value);

// accessing 
// cout << pairname.first; // first value
//cout << pairname.second; // second value

int main(){
    int a= 3;
    int b = 5;

    pair<int, int> p = make_pair(a,b);
    cout<< p.first << endl;
    cout << p.second << endl;
    return 0;

}