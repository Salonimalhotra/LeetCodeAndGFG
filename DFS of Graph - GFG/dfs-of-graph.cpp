// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfsTraversal(int V,vector<int>adj[],int vertex,vector<int>&ans,bool * visited){
        ans.push_back(vertex);
        visited[vertex]=true;
        for(int i=0;i<adj[vertex].size();i++){
            if(visited[adj[vertex][i]]!=true){
                dfsTraversal(V,adj,adj[vertex][i],ans,visited);
            }
        }
        return;
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        bool * visited=new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(visited[i]!=true){
                dfsTraversal(V,adj,i,ans,visited);
            }
        }
        return ans;
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