#include<iostream>
#include<vector>
using namespace std;

vector<int> pairsum(vector<int> arr, int target){
    int st = 0, end = arr.size()-1;
    int currSum = 0;
    vector<int> ans;
    while(st < end){
        currSum = arr[st] + arr[end];
        if(currSum == target){
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }
        else if (currSum > target){
            end--;
        }
        else {
            st++;
        }
    }

    // when pair sum not found it'll return empty vector
    return ans;
}

int main(){
    vector<int> vec = {2,3,6,7,11,15};
    int target = 9;
    vector<int> answer = pairsum(vec,target);
   
    for (int i =0; i<answer.size(); i++){
        cout << answer[i] << ",";

    }
    
    return 0;

}