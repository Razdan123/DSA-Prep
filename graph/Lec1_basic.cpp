#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>> adj;
    
    //Funtion for making the connection --> adding an edge between two nodes
    void addEdge(int u, int v, bool direction){
        //if direction = 0 -> undirected graph
        //if direction = 1 -> directed graph
        
        //creating a connection from u->v
        adj[u].push_back(v);

        if(direction==0){
            adj[v].push_back(u);
        }
    }

    //Function for printing the connections as adjacency List
    void printAdjList(){
        for(auto i: adj){
            cout<<i.first<<"=>>";
            for(auto j: i.second){
                cout<<j<<",";
            }
        cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter the no of Nodes: ";
    cin>>n;

    int m;
    cout<<"Enter the no of edges: ";
    cin>>m;

    graph g;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }

    //Printing the lIst
    g.printAdjList();

    return 0;
}