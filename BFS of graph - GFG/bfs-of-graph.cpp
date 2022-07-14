// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        if(V==0){
            return ans;
        }
        bool * visited=new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        visited[0]=true;
        queue<int>pendingNodes;
        pendingNodes.push(0);
        while(pendingNodes.size()!=0){
            int top=pendingNodes.front();
            pendingNodes.pop();
            ans.push_back(top);
            for(int i=0;i<adj[top].size();i++){
                if(visited[adj[top][i]]!=true){
                    visited[adj[top][i]]=true;
                    pendingNodes.push(adj[top][i]);
                }
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