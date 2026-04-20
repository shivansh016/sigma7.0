#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>

using namespace std;

vector<int> unionOfTwo(vector<int> & arr1, vector<int>& arr2){
    unordered_set<int> s;

    for(int i=0;i<arr1.size(); i++){
        s.insert(arr1[i]); // saare elements ko insert kar do jo unique hoga wahi set me store hoga.
    } 

    for(int j=0; j<arr2.size(); j++){
        s.insert(arr2[j]); // iske bhi saare elements store kar do, jo unique hoga wahi set me store hoga..
    }

    vector<int> ans;
    for(int x : s){
        ans.push_back(x);
    }

    return ans;
}

vector<int> intersectionOfTwo(vector<int> & arr1, vector<int> & arr2){
    unordered_set<int> s;
    
    vector<int> ans;

    for(int i=0; i<arr1.size(); i++){
        s.insert(arr1[i]); // saare elements store kardo jo unique hoga wahi store hoga.
    }

    for(int i=0; i<arr2.size(); i++){
        if(s.count(arr2[i])){
            ans.push_back(arr2[i]); // agar element set me hai aur arr2 me bhi hai to push kar do vector me ... common mil jayenge saare... magar vector hai to duplication ka risk hai(vector thode hi sirf unique elements ko rakhta hai ye to saare hi push kara dega)... 
            s.erase(arr2[i]); // agar ek baar koi common element aa jaye to use remove kar denge set se so that agar wo dobara aaye to ans me na push ho.
        }
    }

   

    return ans;
}

int main(){
    vector<int> arr1 = {7,3,9};
    vector<int> arr2 = {6,3,9,2,9,4};

    vector<int> unionOfBoth = unionOfTwo(arr1, arr2);
    vector<int> intersectionOfBoth = intersectionOfTwo(arr1, arr2);

    cout << "union of elements is : " ;
    for(int i=0; i<unionOfBoth.size(); i++){
        cout << unionOfBoth[i] << " ";
    }
    cout << endl;

    cout << "intersection of elements is :";
    for(int i=0; i<intersectionOfBoth.size(); i++){
        cout << intersectionOfBoth[i] << " ";
    }
    cout << endl;

    return 0;
}