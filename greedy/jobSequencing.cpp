#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second > p2.second; // profit ke basis par sorting..
}
int maxProfit(vector<pair<int, int>> &Jobs){
    // sort karna hai descending me to vector ke begin se end tak..
    sort(Jobs.begin(), Jobs.end(), compare);
    
    // 0th element ka profit ab save karenge aur Safestart ko update..
    int profit = Jobs[0].second; // since profit second wala variable hai har pair me se...
    int safeDeadline = Jobs[0].first+1;  // seedhe 2 bhi likh sakte the but that would've been assumption(ki pahla kaam ki deadline 1 hi thi..)
    
    // ab loop from 1 to n..
    for(int i= 1; i< Jobs.size(); i++){
        if(Jobs[i].first >= safeDeadline){
            profit += Jobs[i].second;
            safeDeadline ++; // matlab current ke 1 din aage se ho sakti hai next work ki deadline
        }
    }

    return profit;

}

int main(){
    int n= 4; // can be any value depending on the user..
    vector<pair<int, int>> Jobs(n, make_pair(0,0)) ;
    Jobs[0] = make_pair(4,20);
    Jobs[1] = make_pair(1,10);
    Jobs[2] = make_pair(1, 40);
    Jobs[3] = {1, 30}; // ye bhi same hai as make pair se assign karte ... sirf jankari ke liye likha hai shivansh so that ki tum bhool na jao...


    cout<<" maximum profit is : "<<maxProfit(Jobs) << endl;
    return 0;
}
