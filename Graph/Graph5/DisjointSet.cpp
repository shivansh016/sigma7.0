//Union Find

#include<vector>
#include<iostream>
using namespace std;

class DisjointSet{
    public:
        int n;
        vector<int> par;
        vector<int> rank;

        DisjointSet(int n){
            for(int i=0; i<n; i++){
                par.push_back(i);
                rank.push_back(0);
            }
        }

        // int find(int x){
        //     if(par[x]==x){
        //         return x;
        //     }

        //     return find(par[x]);
        // }

        int find(int x){//O(alpha) => alpha = some constant
            if(par[x]==x){
                return x;
            }

            return par[x] = find(par[x]); // optimized for skewed trees as well.
        }

        void unionByRank(int a, int b){//O(alpha)
            int parA = find(a);
            int parB = find(b);

            if(parA == parB) return;

            if(rank[parA] == rank[parB]){
                par[parB] = parA;
                rank[parA]++;
            }else if(rank[parA] > rank[parB]){
                par[parB] = parA;
            }else{
                par[parA] = parB;
            }
        }

        void getInfo(int n){
            for(int i=0; i<n; i++){
                cout << i << "par : "  << par[i] << "," << "rank : " << rank[i] << endl;
            }
        }
};

int main(){
    DisjointSet dj(6);

    dj.unionByRank(0,2);
    cout << dj.find(2) << "\n"; //0
    dj.unionByRank(1,3);
    dj.unionByRank(2,5);
    dj.unionByRank(0,3);
    cout << dj.find(2) << "\n" ; //0
    dj.unionByRank(2,4);

    dj.getInfo(6); //getInfo just for our verification... not a part of the Disjoint Set

    return 0;
}

