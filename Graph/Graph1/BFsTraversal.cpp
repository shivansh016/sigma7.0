#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class Graph{
    
        int V;
        list<int>*l;

        public:

            Graph(int V){
                this->V = V;
                l = new list<int> [V];
            }

            void addEdge(int u, int v){
                l[u].push_back(v);
                l[v].push_back(u);
            }

            void print(){
                for(int u=0; u<V; u++){
                    list<int> neighbour = l[u];
                    cout << u << " : " ;

                    for(int v : neighbour){
                        cout << v << " ";
                    }
                    cout << endl;
                }
            }

            void bfs(){ //T.c. O(V+E)  
                queue<int> q;
                vector<bool> vis(V, false);

                q.push(0); // pushing the source or the first node in the queue
                vis[0] = true;

                while(!q.empty()){
                    int u = q.front();//curr vertex
                    q.pop();
                    list<int> neighbour = l[u];

                    cout << u << " ";

                    for(int v : neighbour){
                        if(!vis[v]){
                            q.push(v);
                            vis[v] = true;
                        }
                    }
                }
                cout << endl;
            }

            void dfshelper(int u, vector<bool>&vis){ // note : passing the vis vector by ref. is very necessary as we do want to access the same vector passed not a copy of it.
                vis[u] = true;
                cout << u << " ";
                list<int> neighbour = l[u];

                for(int v : neighbour){
                    if(!vis[v]){
                        dfshelper(v, vis);
                    }
                }
            }

            void dfs(){
                vector<bool> vis(V, false);
                dfshelper(0, vis);
                cout << endl;
            }

            


};

int main(){

    Graph graph(7);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);

    // graph.print();
    // Output:
    // 1 : 0 3 
    // 2 : 0 4 
    // 3 : 1 5 
    // 4 : 2 5 
    // 5 : 3 4 6 
    // 6 : 5 

    graph.bfs();
// output: 
// 0 1 2 3 4 5 6 

    //for the dfs
    // vector<bool> vis (7, false);
    // graph.dfs(0, vis); //source and the visited vector with all false values.
    graph.dfs();
//output:
// 0 1 3 4 2 5 6 

    
    return 0;
}

/*

Time Complexity: O(V+E)
V: Every vertex is enqueued and dequeued exactly once.
E: For every vertex dequeued, we iterate through its adjacency list. 
In an undirected graph, each edge is looked at twice. 
Even if V>E (a sparse graph), the V term remains because you still initialize the vis vector of size V.

*/