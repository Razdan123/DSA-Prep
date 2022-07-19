//Shortest Path in Directed Acyclic Graph using DFS
#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>

using namespace std;

class Graph{
    public:
    //Creating map for storing adjacency list + weightage
    unordered_map<int, list<pair<int,int>>> adj;

    void addEdge(int u, int v, int weight){
        adj[u].push_back({v,weight});
    }

    //Priting our Adjacency List
    void printList(){
        for(auto i :adj){
            cout<<i.first<<" -> ";
            for(auto j : i.second){
                cout<<"("<<j.first<<","<<j.second<<")";
            }cout<<endl;
        }
    }

    //Wring DFS function to get topo sort
    void dfs(int node, unordered_map<int,bool> &visited, stack<int> &topo){
        visited[node]=1;

        for(auto x:adj[node]){
            if(!visited[x.first]){
                dfs(x.first,visited,topo);
            }
        }

        topo.push(node);
    }

    void shortpathFinder(int source, vector<int> &dist, stack<int> &topo){
        while(!topo.empty()){
            int top = topo.top();
            topo.pop();

            if(dist[top]!=INT_MAX){
                for(auto k : adj[top]){
                    if(k.second + dist[top] < dist[k.first]){
                        dist[k.first] = k.second + dist[top];
                    }
                }
            }

        }
    }

};

int main(){
    Graph g;

    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printList();
    int n = 6;

    //Writing dfs function for getting topological sorting
    unordered_map<int,bool> visited;
    stack<int> s;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }

    //Now we have the topo stack. We will create a dist vector and store min values
    vector<int> dist(n);

    //Initialise the dist with infinity 
    for(int i=0; i<n; i++){
        dist[i]=INT_MAX;
    }

    //Intitialising source as 0; because dist will be 0.
    int source = 1;
    dist[source] = 0;

    //Calling the shortFinder function
    g.shortpathFinder(source,dist,s);

    //Printing the paths for different nodes from source node
    int size = dist.size();
    for(int j=0; j<size; j++){
        cout<<dist[j]<<",";
    }cout<<endl;

    return 0;
}