#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

// int main(){
//     priority_queue<pair<string, int>> pq; // basis => first, default => maxHeap


//     pq.push(make_pair("aman", 80));
//     pq.push(make_pair("bhumik", 95));
//     pq.push(make_pair("chetan", 50));

//     while(!pq.empty()){
//         cout << "top : " << pq.top(). first << "," << pq.top().second << endl;
//         pq.pop();
//     }

//     return 0;
//     //OutPUt :
// //       top : chetan,50
// //       top : bhumik,95
// //       top : aman,80
// }

// now for our customized heaps -> min/max , basis first or second... we need to create a struct for the pairs.... and pass the storing vector and the struct to compare in the vector..

struct comparePairs{
    bool operator () (pair<string, int> &p1, pair<string, int> &p2){
        return p1.second < p2.second;

    }
};

int main(){
    priority_queue<pair<string, int> , vector<pair<string, int>> , comparePairs> pq;
    
    pq.push(make_pair("aman", 80));
    pq.push(make_pair("bhumik", 95));
    pq.push(make_pair("chetan", 50));

    while(!pq.empty()){
        cout << "top : " << pq.top(). first << "," << pq.top().second << endl;
        pq.pop();
    }

    return 0; 

}
