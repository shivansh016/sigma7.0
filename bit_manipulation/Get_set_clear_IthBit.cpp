#include<iostream>
using namespace std;

int getIthBit(int num, int i){
    int mask = (1<<i);
    if (!(num & mask)){
        return 0;
    }
    else{
        return 1;
    }

}

void setIthBit(int num, int i){
    int mask = (1<<i);
    cout << (num|mask) << endl; // note using these brackets is necessary otherwise it will show errors
    // the above line will retun the number after setting the ith position  in the given number
}

void clearIthBit(int num, int i){
    int bitmask = ~(1<<i);
    cout << (num&bitmask) << endl;

}

int updateVal(int num, int i, int val){
    if(val == 0){
        num = num & (~(1<<i));
    }
    else {
        num = (num | (1<<i));
    }
    return num;
}

int updatenumM2(int num, int i, int val){
    // clearing ith bit 
    num = num &(~(1<<i));
    //updating the number
    num = (num | (val<<i));
    return num;
}

int clearInRange(int num, int i){ // O(n)
    for (int j=0; j<i; j++){
        num=num&(~(1<<j));
    }
    return num;
}

int cleariBits(int num, int i){
    int bitmask = ((~0)<<i);
    num = num&bitmask;
    return num;
}

int countSetBits(int num){
    int count = 0;
    while(num>0){
        int lastdgt = num&1;
        count += lastdgt;
        num = num >> 1;
    }
    return count;
}

int fastExpo(int x, int n){
    int ans = 1;

    while(n>0){
        int lastBit = n&1;// to access the last bit of the power in binary form
        if(lastBit) { //when last bit is 1 we will multiply the ans by x
            ans = ans * x;
        }
        x = x * x;
        n = n>>1;//updating the power by right shifting the power
        }
    return ans;

}










int main(){
    cout << getIthBit(6,2) << endl; //1
    cout << getIthBit(7,1) << endl; //1
    cout << getIthBit(7,5) << endl; //0

    setIthBit(5,1); //7

    clearIthBit(7,1); //5

    cout << updateVal(7,2,0) << endl; //3
    cout << updateVal(7,3,1) << endl; // 15

    cout << updatenumM2(7,2,0) << endl; //3
    cout << updatenumM2(7,3,1) << endl; //15

    cout << clearInRange(15,2) << endl; //12 but O(n)

    cout << cleariBits(15,2) << endl; //12 with O(1)

    cout << countSetBits(10) << endl; // 1010 =2
    cout << countSetBits(7) << endl; // 111 =3

    cout << fastExpo(3,5) << endl; //243




    return 0;
}