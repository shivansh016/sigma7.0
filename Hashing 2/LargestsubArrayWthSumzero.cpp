#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

//brute force.

// int largestSizeWithSubarrSumZero(vector<int> &arr){
   
//     vector<int> ans;

//     for(int i=0; i<arr.size(); i++){
//         int count =1;
//         int curr = arr[i];
        
//         if(curr == 0){
//             ans.push_back(count);
//         }

//         for(int j=i+1; j<arr.size(); j++){
            
//             curr += arr[j];
//             count ++ ;

//             if(curr == 0){
//                 ans.push_back(count);
//             }
//         }
    
//     }

//     if(ans.size() == 0){
//         return 0;
//     }

//     for(int i=0; i<ans.size(); i++){
//         cout << ans[i] << " "; // printing to check the subarray sizes whose sum is zero.
//     }
//     cout << endl;


//     int max = ans[0];
//     for(int i=0; i<ans.size(); i++){
//         if(ans[i] > max){
//             max = ans[i];
//         }
//     }
//     return max;

// }

int largestSizeWithSubArrSumZero(vector<int> arr){
    int ans = 0;
    int sum = 0;
    
    unordered_map<int, int> mp; // to store the sum of prev. indices.
    for(int j=0;j<arr.size(); j++){
        sum += arr[j];
        if(sum == 0){
            ans = j+1; // agar sum 0 ho jaye to...then.
        }
        if(mp.count(sum)){
            int currLen = j - mp[sum];
            // cout << currLen<<" fug " <<endl;
            ans = max(currLen, ans);
        }else{
            mp[sum] = j;
        }


    //     int flag = 0;
    //     for(pair<int,int> p : mp){
    //         if(p.first == sum && ans < (j-p.second)){
    //             ans = j-p.second;
    //             cout << ans << " hi beautiful ? this is what you expect. " << endl;
    //             flag++;
    //         }
    //     }
    //     if(flag == 0){
    //         mp[sum] = j;
    //     } 


    }

    return ans;
}

int main(){
    vector<int> arr = {15, -2, 2,-8, 1,7,10};

    // cout << largestSizeWithSubarrSumZero(arr) << endl; //for the brute force solution.
    cout << largestSizeWithSubArrSumZero(arr) << endl; // optimized sliding window..&& prefix sum.
    return 0;
}