// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>topo;
        vector<int>inedges(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                inedges[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<inedges.size();i++){
            if(inedges[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(q.size()!=0){
            int topNode=q.front();
            q.pop();
            cnt++;
            for(int i=0;i<adj[topNode].size();i++){
                inedges[adj[topNode][i]]--;
                if(inedges[adj[topNode][i]]==0){
                    q.push(adj[topNode][i]);
                }
            }
        }
        if(cnt==V){
            return false;
        }
        else{
            return true;
        }
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