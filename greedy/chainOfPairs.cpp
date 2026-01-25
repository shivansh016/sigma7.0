#include<iostream>
#include<vector>
#include<algorithm> // for usign sort()
#include<utility> // for pair 
using namespace std;

bool compare(pair<int, int> &p1, pair<int, int> &p2){
    return p1.second < p2.second ; // sort in ascending--> basis of second value

}

int maxChainLen(vector<pair<int, int>> &pairs){
    if(pairs.empty()){// jab empty pairs ho i.e. no pairs ho tab
        return 0;
    }
    sort(pairs. begin(), pairs.end(), compare);

    int chainLen = 1; 
    int currEnd = pairs[0].second; // selected the first pair and currEnd is now the end of the first pair

    for(int i=1; i<pairs.size() ; i++){
        if(pairs[i].first > currEnd){// non overlapping
            chainLen += 1; // selected
            currEnd = pairs[i].second;
        }
    }
    return chainLen;
}

int main(){
    int n = 5; 
    vector<pair<int,int>> pairs(n, make_pair(0,0));
    pairs[0] = {5, 24}; // or make_pair(5,24)
    pairs[1] = {39, 60};
    pairs[2] = {5, 28};
    pairs[3] = {27, 40};
    pairs[4] = {50, 90};

    cout << "max length of chain of pairs : " << maxChainLen(pairs);

    return 0;
}