#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int majorityElement(vector<int> &nums);

int main(){
    vector<int> nums = {1,3,2,5,1,3,1,5,1};
    
    cout << "majority element with frequency greater than n/3 is : " << majorityElement(nums)<< endl;
    return 0;
}

int majorityElement(vector<int> &nums){ // O(N),, O(N).
    int requiredFreq = nums.size()/3;
    unordered_map<int , int> m; // element , freq
    for(int i=0; i<nums.size(); i++){
        if(m.count(m[nums[i]])){
            m[nums[i]]++; // agar exist karta hai pahle se then increase the freq.
        }else{
            m[nums[i]] = 1 ;// nahi exist karta to insert karenge.
        }
    }

    for(pair<int, int> p : m){
        if(p.second > requiredFreq){
            return p.first;
        }
    }
    return -1; // jab koi bhi majority element na ho then return -1.
}