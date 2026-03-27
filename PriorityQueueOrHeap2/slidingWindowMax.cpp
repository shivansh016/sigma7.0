#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> slidingWindowMax(vector<int> &arr,int k){
    vector<int> ans;
    priority_queue<pair<int, int>> pq;

    for(int i=0; i<k; i++){
        pq.push(make_pair(arr[i], i));
    }

    ans.push_back(pq.top().first);

    for(int i=k; i<arr.size(); i++){
        while(!pq.empty() && pq.top().second <= i-k){ // since second is idx..
            pq.pop();
        }
        pq.push(make_pair(arr[i], i));
        ans.push_back(pq.top().first);
    }

    return ans;

}

void printVec(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k=3;

    vector<int> slidingWdMax = slidingWindowMax(nums, k);
    printVec(slidingWdMax);
    return 0;
}