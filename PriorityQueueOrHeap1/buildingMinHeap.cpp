#include<iostream>
#include<vector>
using namespace std;

class minHeap{
        vector<int> vec;
    public:

        void push(int val){
            vec.push_back(val);

            int childIdx = vec.size() -1;
            int parentIdx = (childIdx - 1)/2;

            while(parentIdx >= 0 && vec[childIdx] < vec[parentIdx]){
                swap(vec[childIdx], vec[parentIdx]);
                childIdx = parentIdx;
                parentIdx = (childIdx-1)/2;
            }
        }

        bool isEmpty(){
            return vec.size() == 0;
        }

        int top (){
            if(isEmpty()){
                cout << "heap is empty !" ;
                return -1;
            }
            return vec[0] ;
        }

        void heapify(int parentIdx){
            if(parentIdx >= vec.size()){
                return ;
            }

            int l = 2*parentIdx + 1;
            int r= 2* parentIdx + 2;

            int minIdx = parentIdx;
            if(l< vec.size() && vec[l] <vec[minIdx]){
                minIdx = l;
            }
            if(r < vec.size() && vec[r] < vec[minIdx]){
                minIdx = r;
            }

            
            if(parentIdx != minIdx){
                swap(vec[parentIdx], vec[minIdx]); // otherwise when parentIdx is same as the minIdx no need to swap and recursive call also should be done only when the parentIdx is not the minIdx.
                heapify(minIdx);
            }
        
        }
        void pop(){
            if(isEmpty()){
                return;
            }
            // 1. swap with last vector element.
            swap(vec[0], vec[vec.size() - 1]);
            // 2. delete the last element
            vec.pop_back();
            // 3. heapify
            heapify(0);
        }
       
        
};

int main(){
    minHeap mheap;
    mheap.push(23);
    mheap.push(38);
    mheap.push(40);
    mheap.push(80);

    while(!mheap.isEmpty()){
        cout << "top : " << mheap.top() << endl; //23 38 40 80
        mheap.pop();
    }

    return 0;
}