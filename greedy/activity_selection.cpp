#include<iostream>
#include<vector>
using namespace std;

int selectMaxActivity(vector<int> &start, vector<int> &end){
    //sort on basis of end time ...already sorted 
    //select 1st activity as it is ending at first,,,
    int count = 1;
    int currEnd = end[0];
    for (int i = 1 ; i<start.size(); i++){
        if(start[i]>=currEnd){//only non overlapping ko select kiya..
            count++;
            currEnd = start[i];
        }
    }
    return count;

}

int select_nameMaxActivity(vector<int> &start, vector<int> &end){
    //sort on basis of end time ...already sorted 
    //select 1st activity as it is ending at first,,,
    int count = 1;
    int currEnd = end[0];
    cout<< "A" << 0 << endl; 
    for (int i = 1 ; i<start.size(); i++){
        if(start[i]>=currEnd){//only non overlapping ko select kiya..
            cout << "A" << i << endl;
            count++;
            currEnd = start[i];
        }
    }
    return count;

}

int main(){
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};

    cout << "maximum activities that can be selected are" << selectMaxActivity(start, end) << endl;
    cout << select_nameMaxActivity(start, end) << endl;
}