#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Heap{
    vector<int> vec;
    public: 
        void push(int val){ // O(logn) 
            vec.push_back(val);
            int childIdx = vec.size() -1 ;// since element is inserted at the end 
            int parentIdx = (childIdx-1)/2;

            while(parentIdx >= 0 && vec[childIdx] > vec[parentIdx]){
                swap(vec[childIdx], vec[parentIdx]);
                childIdx = parentIdx;
                parentIdx = (childIdx-1)/2;
            }
        }

        // heapify function for the pop() function...
        void heapify(int parIdx){
            if(parIdx > vec.size()){
                return ;
            }

            int l = 2* parIdx +1;
            int r = 2* parIdx +2;

            int maxIdx = parIdx; // initially assuming that the parIdx is the idx with max value...
         
            if(l< vec.size() && vec[l] > vec[maxIdx]){ // check validity of the l and then check the value at l..
                maxIdx = l;
            }
            if(r < vec.size() && vec[r] > vec[maxIdx]){ // check validity at the r and then check the value at the r..
                maxIdx = r;
            }

            swap(vec[maxIdx], vec[parIdx]);

            if(maxIdx != parIdx){ // jab child node ko swap karenge to hi recursive calling hogi...
                heapify(maxIdx);
            }
        }
        void pop(){
            if(isEmpty()){
                return;
            }
            //step 1;
            swap(vec[0], vec[vec.size()-1]); // swap with the last element
            //step2;
            vec.pop_back(); // remove the last element
            // step 3;
            heapify(0);
        }

        int top(){
            if(isEmpty()){
                cout << "heap is empty \n" ;
                return -1; // i.e. throws exception
            }
            return vec[0]; //most priority element will be at top i.e. first element of the vector
        }

        bool isEmpty(){
            return vec.size() == 0; // empty vector represent that our heap is empty.
        }
};



int main(){
    Heap heap;
    heap.push(23);
    heap.push(10);
    heap.push(80);
    heap.push(28);
    cout << endl << "is empty : " <<heap.isEmpty() << endl;
    cout << "top : " << heap.top() <<endl; // 80 at top shows that we implemented the maxHeap correctly.
    heap.pop();
// now we are iterating and printing the remaining elements in the heap as.. 28, 23 , 10...

    while(!heap.isEmpty()){
        cout << "top : " << heap.top() << endl;
        heap.pop();
    }

    return 0;
}



