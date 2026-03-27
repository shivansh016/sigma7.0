#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Row{
    public:
        int soldierCount;
        int idx;

        Row(int soldierCount, int idx){
            this->soldierCount = soldierCount;
            this->idx = idx;
        }

        // operator overloading for the minHeap..
        bool operator < (const Row & obj) const{
            if(this->soldierCount == obj.soldierCount){ // jab soldier same ho to priority idx ko 
                return this->idx > obj.idx; // > shows minHeap... i.e. smaller is prior
            }

            return this->soldierCount > obj.soldierCount;
        }
};

void weakestSoldier(vector<vector<int>> &matrix, int k){
    vector<Row> rows;

    for(int i=0; i<matrix.size(); i++){
        int sCount = 0;
        for(int j=0; j<matrix[i].size(); j++){
            if(matrix[i][j] == 1){
                sCount ++;
            }
        }
        rows.push_back(Row(sCount , i));
    }

    priority_queue<Row> pq(rows.begin(), rows.end());

    for(int i=0; i<k; i++){
        cout << "Row : " << pq.top().idx << endl;
        pq.pop();
    }
    cout << endl;
}

int main(){
    vector<vector<int>> matrix = {{1,0,0,0},
                                {1,1,1,1},
                                {1,0,0,0},
                                {1,0,0,0}};
    int k= 2;
    weakestSoldier(matrix, k);
    return 0;

}