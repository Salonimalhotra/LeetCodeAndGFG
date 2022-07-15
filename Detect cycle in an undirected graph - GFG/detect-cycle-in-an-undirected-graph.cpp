// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool helper(int vertex,int par,int V,vector<bool>&visited,vector<int>adj[]){
        visited[vertex]=true;
        for(auto i:adj[vertex]){
            if(visited[i]==true){
                if(i==par){
                    continue;
                }
                else{
                    return true;
                }
            }
            bool smallAns=helper(i,vertex,V,visited,adj);
            if(smallAns){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(visited[i]!=true){
                bool ans=helper(i,-1,V,visited,adj);
                if(ans){
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