#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void heapify(int i, vector<int> & nums, int n){
    int left = 2*i +1;
    int right = 2*i + 2;
    int minI = i;

    if(left < n && nums[left] < nums[minI]){
        minI = left;
    }
    if(right < n && nums[right ] < nums[minI]){
        minI = right ;
    }

    if(minI != i){
        swap(nums[i], nums[minI]);
        heapify(minI, nums, n);
    }
}

void heapSort(vector<int> & nums){{
    int n = nums.size();

    //1.build minHeap
    for(int i= n/2-1; i>=0; i--){
        heapify(i, nums, n);
    }

    //2. to move the elements at the end
    for(int i= n-1; i>=0; i--){
        swap(nums[0], nums[i]);
        heapify(0, nums, i);
    }
}

}
void printArr(vector<int> & nums){{
    for(int i =0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

}

int main(){
    vector<int> nums = {1,4,2, 5,3};
    heapSort(nums);
    //to verify ..should print elements in descending order.
    printArr(nums);
    return 0;
}