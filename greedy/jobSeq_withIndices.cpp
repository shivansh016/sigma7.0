// ise baad me dekhna hai...


#include<iostream>
#include<utility> //for the make_pair... 
#include<vector>
#include<algorithm> // for the sort()..
using namespace std;

class Job{
     public:
        int idx;
        int deadline;
        int profit;
      
        Job(int idx, int deadline, int profit){
            this->idx = idx;
            this->deadline = deadline; 
            this->profit = profit;
        }

}; 

int maxProfit(vector<pair<int , int>> Pairs){
    int n = Pairs.size();

    vector<Job> jobs; // created a vector of the class objects..

    for(int i =0; i<n; i++){
        jobs.emplace_back(i, Pairs[i].first, Pairs[i].second); // idx, deadline, value..
    }

    sort(jobs.begin(), jobs.end(), []( Job &a, Job &b){// sorting using the lambda func. and capture list..
        return a.deadline < b.deadline; // return in ascend. comparing the deadline ..
    }); 

    sort(jobs.begin(), jobs.end(), []( Job &a, Job &b){// sorting using the lambda func. and capture list..
        if(a.deadline == b.deadline){
            return a.profit>b.profit;
        }else{
            return a.deadline<b.deadline;
        } // return in ascend. comparing the profit ..
    }); 

    int profit = jobs[0].profit;
    cout << "selecting job" << jobs[0].idx << endl; // yahan seedhe hi mat print karwa dena 0 index as we want to print the idx of the original pair that we passed to the maxProfit();
    int safeDeadline = jobs[0].deadline;

    for(int i = 1 ; i<n; i++){
        if(safeDeadline < jobs[i].deadline){
            profit += jobs[i].profit;
            cout << "selecting job" << jobs[i].idx << endl;
            safeDeadline ++;
        }
    }

    return profit;


}

int main(){
    vector<pair<int, int>>Pairs = {
    {2,100},  // job0
    {2,19},   // job1
    {1,27},   // job2
    {1,25},   // job3
    {3,15}    // job4
    
}; // correct output : 142
   // my code : 115 ........................................................................


    cout<<" maximum profit is : "<<maxProfit(Pairs) << endl;
    return 0;
}

//     int n= 4; // can be any value depending on the user..
//     vector<pair<int, int>> Pairs(n, make_pair(0,0)) ;
//     Pairs[0] = make_pair(4,20);
//     Pairs[1] = make_pair(1,10);
//     Pairs[2] = make_pair(1, 40);
//     Pairs[3] = {1, 30}; // ye bhi same hai as make pair se assign karte ... sirf jankari ke liye likha hai shivansh so that ki tum bhool na jao...


// #include<iostream>
// #include<utility> //for the make_pair... 
// #include<vector>
// #include<algorithm> // for the sort()..
// using namespace std;

// class Job{
//      public:
//         int idx;
//         int deadline;
//         int profit;
      
//         Job(int idx, int deadline, int profit){
//             this->idx = idx;
//             this->deadline = deadline; 
//             this->profit = profit;
//         }

// }; 

// int maxProfit(vector<pair<int , int>> Pairs){
//     int n = Pairs.size();

//     vector<Job> jobs; // created a vector of the class objects..

//     for(int i =0; i<n; i++){
//         jobs.emplace_back(i, Pairs[i].first, Pairs[i].second); // idx, deadline, value..
//     }

//     sort(jobs.begin(), jobs.end(), []( Job &a, Job &b){// sorting using the lambda func. and capture list..
//         return a.profit > b.profit; // return in desc. comparing the profit ..
//     }); 

//     int profit = jobs[0].profit;
//     cout << "selecting job" << jobs[0].idx << endl; // yahan seedhe hi mat print karwa dena 0 index as we want to print the idx of the original pair that we passed to the maxProfit();
//     int safeDeadline = jobs[0].deadline;

//     for(int i = 1 ; i<n; i++){
//         if(safeDeadline < jobs[i].deadline){
//             profit += jobs[i].profit;
//             cout << "selecting job" << jobs[i].idx << endl;
//             safeDeadline ++;
//         }
//     }

//     return profit;


// }

