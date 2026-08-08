#include<iostream>
#include<vector>
using namespace std;

class Edge{
    public : 
            int wt; //weight
            int v; //destination

            Edge(int v, int wt){
                this->v = v;
                this->wt = wt;
            }


};

void BellmanFord(int src, vector<vector<Edge>> &graph, int V){ //O(V.E)
    vector<int> dist(V, INT32_MAX);

    dist[src] = 0;

    for(int i=0; i<V-1; i++){//V-1 times loop chalayi //V times
        for(int u=0; u<V; u++){// then har node pe gaye one by one.. //Edge (E) times
            for(Edge e : graph[u]){//ed node ke saare neighbour ko liye aur edge relaxation perform kari
                if(dist[e.v] > dist[u] + e.wt){
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    for(int i=0; i<V; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main(){
    //BellmanFord 
    int V= 5;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

   
    graph[1].push_back(Edge(2,-4));

    graph[2].push_back(Edge(3,2));

    graph[3].push_back(Edge(4,4));

    graph[4].push_back(Edge(1,-1));

    BellmanFord(0, graph, V);

    return 0;

}

// Output :
// 0 2 -2 0 4 