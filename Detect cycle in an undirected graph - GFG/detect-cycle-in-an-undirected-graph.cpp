// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle1(int V,int vertex,vector<int> adj[],bool * visited){
        queue<pair<int,int>>pendingVertices;
        pendingVertices.push(make_pair(vertex,-1));
        visited[vertex]=true;
        while(pendingVertices.size()!=0){
            pair<int,int>topVertex=pendingVertices.front();
            pendingVertices.pop();
            for(int i=0;i<adj[topVertex.first].size();i++){
                if(visited[adj[topVertex.first][i]]==true){
                    if(adj[topVertex.first][i]==topVertex.second){
                        continue;
                    }
                    else{
                        return true;
                    }
                    
                }
                else{
                    visited[adj[topVertex.first][i]]=true;
                    pendingVertices.push(make_pair(adj[topVertex.first][i],topVertex.first));
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool * visited=new bool[V];
        
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        
        for(int i=0;i<V;i++){
            if(visited[i]!=true){
            bool ans=isCycle1(V,i,adj,visited);
            if(ans==true){
                return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends