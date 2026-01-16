#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int maxAreaHistogram(vector<int> height){

    int n = height.size();

    vector<int> nsL(n);// for next small left 
    vector<int> nsR(n);// for next small right
    stack<int> s;

    //
        nsL[0] = -1; // first element ka left smaller nahi hota
        s.push(0);// stack me ham indices daal rahe
        for (int i=1; i<height.size(); i++){
            int curr = height[i];
            while(!s.empty() && curr<= height[s.top()]){
                s.pop();
            }
            if (s.empty()){
                nsL[i] = -1;
            }else{
                 nsL[i] = s.top(); //nsL me bhi index hi daal rahe i.e. next smaller left index
            }
           
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }// stack ko khali kara for nsR;
       
        //nsR...
        
        s.push(n-1);// last wale ka koi bhi next right smaller nahi hota
        nsR[n-1] = n;// since n = index of last element and n+1 = number of elements


        for(int i= n-2; i>=0; i-- ){
            int curr = height[i];
            while(!s.empty() && curr <= height[s.top()]){
                s.pop();
            }
            if(s.empty()){
                nsR[i] = n;
            }

            else{
                nsR[i] = s.top();
            }

            s.push(i);
        }

        for(int i =0; i<height.size(); i++){
            cout<< nsR[i] << " ";
            
        }
        cout << endl;
        for(int i =0; i<height.size(); i++){
            cout<< nsL[i] << " ";
            
        }
        cout << endl;


        // area
        int maxArea = 0;
        for(int i =0 ; i<n; i++){
            int ht = height[i];
            int wd = nsR[i] - nsL[i] -1;
            int area = ht*wd;
            maxArea = max(area, maxArea);
        }
return maxArea;

}

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    cout << "max area of histogram : "<< maxAreaHistogram(heights) << "\n";
    
    return 0;
    
}