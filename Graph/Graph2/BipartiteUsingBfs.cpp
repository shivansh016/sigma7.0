#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>* l;
    bool isUndir;
    public:
         
        Graph(int V, bool isUndir = false){
            this->V = V;
            l = new list<int> [V];
            this->isUndir= isUndir;
        }

        ~Graph(){
            delete [] l;
        }

        void addEdge(int u, int v){
            l[u].push_back(v);
            if(isUndir){
                l[v].push_back(u);
            }
            
        }

        void print(){
            for(int i=0; i<V; i++){
                cout << i << " : ";
                list<int> neighbour = l[i];
                for(int v : neighbour){
                    cout << v << " ";
                }
                cout << endl;
            }
        }

        bool bfsIsBipartite(){
            vector<bool>vis(V,false);
            vector<int>color(V, -1);
            queue<int> q;
            q.push(0);
            vis[0] = true;
            color[0] = 0;

            while(!q.empty()){
                int curr = q.front();
                q.pop();
                list<int> neighbour = l[curr];

                for(int v : neighbour){
                    if(!vis[v]){
                        q.push(v);
                        vis[v]= true;
                        if(color[curr] == 0){
                            color[v] = 1;
                        }else{
                            color[v] = 0;
                        }

                    }else{
                        if(color[v] == color[curr]){
                            return false;
                        }
                    }
                }
            }
            return true;
        }
};

int main(){
    Graph graph1(4, true);
    graph1.addEdge(0,1);
    graph1.addEdge(0,2);
    graph1.addEdge(1,3);
    graph1.addEdge(2,3);
    cout << "Graph 1 ->" << endl;
    graph1.print();

    cout << "-------------" << endl;
    cout << "is graph 1 bipartite(0-> no, 1->yes) : " << graph1.bfsIsBipartite() << endl; //1
    cout << "-------------" << endl;

    Graph graph2(5, true);
    graph2.addEdge(0,1);
    graph2.addEdge(0,2);
    graph2.addEdge(1,3);
    graph2.addEdge(2,4);
    graph2.addEdge(3,4);

    cout << "Graph 2 -> " << endl;
    graph2.print();

    cout << "-------------" << endl;
    cout << "is graph 2 bipartite(0-> no, 1->yes) : " << graph2.bfsIsBipartite() << endl; //0
    cout << "-------------" << endl;
    return 0;
    
}

// Output :


// Graph 1 ->
// 0 : 1 2 
// 1 : 0 3 
// 2 : 0 3 
// 3 : 1 2 
// -------------
// is graph 1 bipartite(0-> no, 1->yes) : 1
// -------------
// Graph 2 -> 
// 0 : 1 2 
// 1 : 0 3 
// 2 : 0 4 
// 3 : 1 4 
// 4 : 2 3 
// -------------
// is graph 2 bipartite(0-> no, 1->yes) : 0
// -------------