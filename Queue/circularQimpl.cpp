#include<iostream>
using namespace std;

class Queue{
    int *arr; // to store the values of the queue using array implementation... we are creating it dynamically so that user can pass the size of arr.. even though it will be fixed
    int capacity;
    int currSize;

    int r,f ; // r->rear, f->front

    public:
        Queue(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;

        f=0;
        r=-1;
    }

    ~Queue(){
        delete[] arr;

        cout << "deleting arr and queue\n";
    }
        void push(int val){
            if(currSize== capacity){
                cout << "Queue already full --> can't push\n" ;
                return ;
            }
            r = (r+ 1)%capacity;
            arr[r] = val;
            currSize ++;
        }

        void pop(){
            if(empty()){
                cout << "already empty\n";
                return;
            }
            f = (f+1)%capacity;
            currSize --;
        }

        int front(){
            if(empty()){
                cout << "queue is empty... \n";
                return -1;
            }
            else{
                return arr[f];
            }
           
        }
        
        bool empty(){
            return currSize == 0;
        }
    

};

int main(){

    Queue q(4);// aise hi bracket me ham size paas karte hai... vector wagaira ki bhi..
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.front() << endl;// 1

    q.pop();// deletes the front element
    cout << q.front()<< endl;// will now show 2

    q.push(5);
    cout << q.front()<< endl; //ab bhi 2 hi dikhayega magar 0 index par 5 aa jayega;




    return 0;
}