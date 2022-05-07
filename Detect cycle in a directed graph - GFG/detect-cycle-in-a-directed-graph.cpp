// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool helper(int i,bool * visited,bool * dfs_visited,int V,vector<int>adj[]){
        visited[i]=true;
        dfs_visited[i]=true;
        for(int j=0;j<adj[i].size();j++){
            if(visited[adj[i][j]]!=true){
                 bool ans=helper(adj[i][j],visited,dfs_visited,V,adj);
                 if(ans==true){
                     return true;
                 }
            }
            else{
                if(dfs_visited[adj[i][j]]==true){
                    return true;
                }
            }
        }
        dfs_visited[i]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool * visited=new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        
        bool * dfs_visited=new bool[V];
        for(int j=0;j<V;j++){
            dfs_visited[j]=false;
        }
        
        for(int i=0;i<V;i++){
            if(visited[i]!=true){
                bool ans=helper(i,visited,dfs_visited,V,adj);
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

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends