#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class Graph{
    int V;
    list<int> * l;
    bool isUndir;

    public: 

        Graph(int V, bool isUndir = false){
            this->isUndir = isUndir;
            this->V = V;
            l = new list<int> [V];
        }

        ~Graph(){
            delete [] l ;
        }

        void addEdge(int u, int v){
            l[u].push_back(v);
            if(isUndir){
                l[v].push_back(u);
            }
        }

        void calcIndegree(vector<int> &indeg){
            for(int i=0; i<V; i++){
                for(int v : l[i]){ //i->v
                    indeg[v]++;
                }
            }
        }

        void topoSort2(){
            vector<int> indeg(V,0);
            calcIndegree(indeg);
            queue<int> q;
            for(int i=0; i<V; i++){
                if(indeg[i] == 0){
                    q.push(i);
                }
            }

            while(!q.empty()){
                int front = q.front();
                q.pop();
                cout << front << " ";
                for(int v : l[front]){
                    indeg[v]--;
                    if(indeg[v] == 0){
                        q.push(v);
                    }
                }
            }
            cout << endl;
        }
};
int main(){
     Graph graph(6, false);

    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,1);
    graph.addEdge(4,0);
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.topoSort2();

    return 0;

}

// Output:
// 4 5 0 2 3 1 