// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Edge{
  public:
  int source;
  int dest;
  int weight;
  Edge(int s,int d,int w){
      source=s;
      dest=d;
      weight=w;
  }
  
};
bool compare(Edge e1,Edge e2){
    if(e1.weight<e2.weight){
        return true;
    }
    else{
        return false;
    }
}
int findParent(int x,int *parent){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=findParent(parent[x],parent);
}
void union1(int x,int y,int *parent,int *rank){
    x=findParent(x,parent);
    y=findParent(y,parent);
    
    if(rank[x]<rank[y]){
        parent[x]=y;
    }
    else if(rank[x]>rank[y]){
        parent[y]=x;
    }
    else{
        parent[x]=y;
        rank[y]++;
    }
    return;
}
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<Edge>edges;
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                Edge edge1(i,adj[i][j][0],adj[i][j][1]);
                // edge1.source=i;
                // edge1.dest=adj[i][j][0];
                // edge1.weight=adj[i][j][1];
                edges.push_back(edge1);
            }
            
        }
        
        sort(edges.begin(),edges.end(),compare);
        
        int * parent=new int [V];
        int * rank=new int[V];
        for(int i=0;i<V;i++){
            parent[i]=i;
            rank[i]=0;
        }
        
        int x=0;
        int cost=0;
        vector<Edge>res;
        int i=0;
          while(i<V-1){
              Edge e1=edges[x];
              int source=e1.source;
              int destination=e1.dest;
              int weight=e1.weight;
              
              if(findParent(source,parent)==findParent(destination,parent)){
                  x++;
              }
              else{
                  res.push_back(e1);
                  cost+=weight;
                  union1(source,destination,parent,rank);
                  x++;
                  i++;
              }
        }
        // for(int i=0;i<res.size();i++){
        //     cout<<res[i].source<<" "<<res[i].dest<<" "<<res[i].weight<<endl;
        // }
        return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends