#include<iostream> 
#include<algorithm>// for sorting
#include<vector>
using namespace std;


int getMinChange(vector<int> &coins, int V){
    sort(coins.begin(), coins.end()); // sort in ascending and travel the vector in reverse otherwise to travel forward sort descending..
    int n = coins.size()-1;
    int ans = 0;

    for(int i=n; i>=0 && V>0; i--){
        if(coins[i] <= V){
            ans += V/coins[i]; // for getting the exaxt number of coins of same value
            V = V%coins[i]; // save the remainder to the V
        }
    }

    return ans;
}

int main(){
    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    int V = 1099;
    cout << "MIN indian coins : " << getMinChange(coins, V) << endl;
    return 0;
}


//........................my code..............................

// bool compare(int a, int b){
//     return a>b; // so that we can compare the individual elements of the vector and make the vector sorted in descending order...
// }


// int indianCoins(vector<int> &coins, int value){
//     sort(coins.begin(), coins.end(), compare);

//     int ans =0;
    
//         for(int i =0; i<coins.size();i++){
//             while(coins[i]<=value){ // Earlier, using 'if' would subtract the coin only once and then 
//                                       //move to the next index (i increments due to the for-loop).
//                                       // Using 'while' keeps the index 'i' fixed and repeatedly subtracts
//                                      // the same coin until its value becomes greater than the remaining amount.

//                 ans ++;
//                 value -= coins[i];
//             }
//         }
    
//     return ans;    
// }
