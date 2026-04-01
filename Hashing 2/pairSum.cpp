#include<bits/stdc++.h>
using namespace std;

vector<int> pairSum(vector<int> & nums, int target);
vector<int> optimized(vector<int> &nums, int target);



int main(){
    vector<int> nums = {1,2,7,11, 15,5,9};
    int target = 9;

    // vector<int> ans = pairSum(nums, target);

    // for(auto x: ans){
    //     cout << x << " " ;
    // }
    // cout << endl;

    vector<int> ans = optimized(nums, target);
   for(auto x: ans){
        cout << x << " " ;
    }
    cout << endl;
    return 0;
}


// (nlogn) ==> sorting and two pointer.
vector<int> pairSum(vector<int> &nums, int target){
    vector<pair<int, int>> vec;

    for(int i=0; i<nums.size(); i++){
        vec.push_back(make_pair(nums[i], i)); // nums[i] pahle kyuki sorting first element ke basis pe hoti 
    }

    sort(vec.begin(), vec.end());

    int st = 0;
    int end = nums.size() -1;

    while(st < end){
        int sum = vec[st].first + vec[end].first;

        if(sum == target ){
            return {vec[st].second , vec[end].second}; // 1 2 for this specific problem...
        }else if(sum> target ){
            end --;
        }else {
            st ++;
        }
    }

    return {};
}

// optimized approach using unordered_maps..


vector<int> optimized(vector<int> & nums, int target){
    unordered_map<int,int> m;
    vector<int> ans;

    for(int i=0; i<nums.size(); i++){

        int complement = (target - nums[i]);

        if(m.count(complement)){
            ans.push_back(m[complement]);
            ans.push_back(i);
            break;
        }

        m[nums[i]] = i;
    }

    return ans;
}