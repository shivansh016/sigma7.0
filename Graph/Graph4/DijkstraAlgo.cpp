#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;

class Edge{
    public:
        int v; 
        int wt;
     
        Edge(int v , int wt){
            this->v = v;
            this->wt =wt ;
        }
};

void dijkstra(int src, vector<vector<Edge>> &graph, int V){
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;//sorts on basis of first element of pair
    //dist[u],v
    vector<int> dist(V, INT32_MAX);


    pq.push(make_pair(0,src));//dist, node
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        vector<Edge> edge = graph[u];
        for(Edge e : edge){
            if(dist[e.v] > dist[u] + e.wt){
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v],e.v));
            }
        }
    }

    for(int i=0; i<dist.size(); i++){
        cout << dist[i] << " ";
    }
    cout << endl;


}



int main(){
        int V= 6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(3,7));
    graph[1].push_back(Edge(2,1));

    graph[2].push_back(Edge(4,3));

    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(5,5));

    dijkstra(0, graph, V);

    return 0;


}

// output:

// 0 2 3 8 6 9 