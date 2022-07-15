// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool detectCycle(int i,vector<bool>&visited,vector<bool>&dfsvisited,int V,vector<int>adj[]){
        visited[i]=true;
        dfsvisited[i]=true;
        for(auto j:adj[i]){
            if(visited[j]!=true){
              bool check=detectCycle(j,visited,dfsvisited,V,adj);
                if(check){
                    return true;
                }
            }
            else if(dfsvisited[j]){
                return true;
            }
        }
        
        dfsvisited[i]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V,false);
        vector<bool>dfsvisited(V,false);
        
        for(int i=0;i<V;i++){
            if(visited[i]!=true){
                bool check=detectCycle(i,visited,dfsvisited,V,adj);
                if(check){
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