#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int connectNropes(vector<int> & ropes){
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end()); // greater<int> and vector<int> used as we needed the minheap... and ropes is passed from ropes.begin() to ropes.en() instead of loop as we want less t.c. so O(N)...
    int cost = 0;

    while(pq.size()>1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        cost += min1 + min2;
        pq.push(min1+ min2);
    }

    cout << "min cost : " << cost << endl;
    return cost;
}

int main(){
    vector<int> ropes = {4,2,3, 6};
    connectNropes(ropes);
    return 0;
}