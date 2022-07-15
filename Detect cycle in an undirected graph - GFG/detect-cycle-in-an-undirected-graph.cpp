// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool helper(int vertex,int V,vector<bool>&visited,vector<int>adj[]){
        queue<pair<int,int>>pending;
        visited[vertex]=true;
        pending.push(make_pair(vertex,-1));
        while(!pending.empty()){
            pair<int,int>top=pending.front();
            pending.pop();
            for(auto i:adj[top.first]){
                if(visited[i]==true){
                    if(top.second!=i){
                        return true;      
                    }
                    else{
                        continue;
                    }
                  
                }
                else{
                    visited[i]=true;
                     pending.push(make_pair(i,top.first));
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(visited[i]!=true){
                bool ans=helper(i,V,visited,adj);
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