#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void stockSpan(vector<int> &stock,  vector<int> &span){
    stack<int> ans;
   
    span[0] = 1;
    ans.push(0);

    for(int i = 1; i<stock.size(); i++){
        while(!ans.empty() && stock[i]>= stock[ans.top()]){
            ans.pop();

        }
        if(ans.empty()){
            span[i] = i+1;
            ans.push(i);
        }
        else{
            int prevHigh = ans.top();
            span[i] = i - prevHigh;
            ans.push(i);
        }
    }


    for(int i=0; i<span.size(); i++){
        cout << span[i] << " ";
    }
    cout << "\n";
}



int main(){
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span = {0,0,0,0,0,0,0};
    stockSpan(stock, span);

   

    return 0;

}