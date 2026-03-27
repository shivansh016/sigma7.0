#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Car{
    public:
        int idx;
        int distSq;

        Car(int idx, int distSq){
            this->idx = idx;
            this->distSq = distSq;
        }

        bool operator < (const Car & obj) const{
            return this->distSq > obj.distSq; // > since we need minHeap..
        }
};


void nearbyCars(vector<pair<int, int>> pos, int k){
    vector<Car> cars;
// finding the distSq and pushing the Car items with idx, distSq in cars vector...
    for(int i=0; i<pos.size(); i++){ // O(n)
        int distSq = (pos[i].first * pos[i].first ) + (pos[i].second * pos[i].second) ;
        cars.push_back(Car(i, distSq));
    }

    priority_queue<Car> pq(cars.begin(), cars.end()); // O(n)
    // or 
    // for(int i=0; i<cars.size(); i++){ // O(nlogn) // but we don't want that t.c. so we used the above given creating method for the priority_queue...
    //     pq.push(cars[i]);
    // }

    // we did operator overloading in class Car ..
    for(int i=0; i<k; i++){
        cout << "Car" <<pq.top().idx << endl;
        pq.pop();
    }
}

int main(){
    vector<pair<int, int>> pos;

    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5, 1));
    pos.push_back(make_pair(4, -2));

    int k = 2;

    nearbyCars(pos, k);
    return 0;
}