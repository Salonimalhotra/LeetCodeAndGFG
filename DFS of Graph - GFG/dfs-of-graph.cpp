// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfsTraversal(int V,vector<int>adj[],vector<bool>&visited,int i,vector<int>&dfs){
        if(visited[i]==true){
            return;
        }
        visited[i]=true;
        dfs.push_back(i);
        for(int j=0;j<adj[i].size();j++){
            if(visited[adj[i][j]]!=true){
                dfsTraversal(V,adj,visited,adj[i][j],dfs);
            }
        }
        return;
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>dfs;
        if(V==0){
            return dfs;
        }
        vector<bool>visited(V,false);
        dfsTraversal(V,adj,visited,0,dfs);
        return dfs;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends