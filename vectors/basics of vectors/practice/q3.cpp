//later ; it is wrong as of now
#include<iostream>
#include<vector>
using namespace std;

vector<int> istriplet(vector<int> v){
    int currSum=0;
    vector<int> ans;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size(); j++){
            for(int k=0; k<v.size(); k++){
                if(i==j || j==k || k==i){
                    continue;
                }
                
                else {
                    currSum=v[i]+v[j]+v[k];
                    if(currSum==0){
                        ans.push_back(v[i]);
                        ans.push_back(v[j]);
                        ans.push_back(v[k]);
                        cout<<" three sum " << ans[i] << ans[j] << ans[k] << endl;


                    }
                }

            }
        }
    }
    return ans;
}

int main(){
    vector<int> vec = {-1,0,1,2,-1,4};
    vector<int> answer = istriplet(vec);
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << " ";
    }
    return 0;
}