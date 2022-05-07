// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectCycle(int vertex,int parent,int V,vector<int>adj[],bool * visited){
        visited[vertex]=true;
        for(int i=0;i<adj[vertex].size();i++){
            if(visited[adj[vertex][i]]!=true){
                if(detectCycle(adj[vertex][i],vertex,V,adj,visited)){
                    return true;
                }
            }
            else{
                 if(adj[vertex][i]!=parent){
                     return true;
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
               bool ans1=detectCycle(i,-1,V,adj,visited);
               if(ans1==true){
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