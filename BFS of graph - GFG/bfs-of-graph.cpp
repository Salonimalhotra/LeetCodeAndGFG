// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>BFS_traversal;
        int firstVertex=0;
        queue<int>pendingvertices;
        pendingvertices.push(firstVertex);
        bool * visited=new bool[V];
        
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        visited[0]=true;
        while(pendingvertices.size()!=0){
            int topvertex=pendingvertices.front();
            pendingvertices.pop();
            // visited[topvertex]=true;
            BFS_traversal.push_back(topvertex);
            for(int i=0;i<adj[topvertex].size();i++){
                if(visited[adj[topvertex][i]]!=true){
                    pendingvertices.push(adj[topvertex][i]);
                    visited[adj[topvertex][i]]=true;
                }
            }
            
        }
        
        return BFS_traversal;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends