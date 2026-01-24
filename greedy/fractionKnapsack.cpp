#include<iostream>
#include<vector>
#include<utility> // for pairs 
#include<algorithm> // sort ke liye
using namespace std;

bool compare(pair<double, int> p1, pair<double, int> p2){
    return p1.first > p2.first; // dono pair ke first i.e. ratio ko compare karne ke liye ,,, descend -->sorting
}

double fractionKnapsack(vector<int> value, vector<int> weight, int w){
    double ans =0;

    int n = value.size();
    vector<double> ratio(n, 0); // will store n elements each initialized by zero
    for(int i = 0; i<n; i++){
        ratio[i] = (double)value[i]/weight[i]; //to pass data to ratio vector
    }

    vector<pair<double, int>> p (ratio.size(), make_pair(0.0,0)); // pair banane ke liye
    for(int i =0; i<n; i++){
        p[i] = {ratio[i], i};
    }

    sort(p.begin(), p.end(), compare);

    for(int i =0; i<ratio.size(); i++){
        int idx = p[i].second;
        if(weight[idx]<= w){
            ans += value[idx];
            w -= weight[idx];
        }
        else{
            ans += ratio[idx]* w;
            w =0; //kyuki yahi last case hoga to capacity 0 hi ho zani hai
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> value = {60,100,120};
    vector<int> weight = {10,20,30};
    int w = 50;

    cout << fractionKnapsack(value, weight, w) << endl;
    return 0;
    
}