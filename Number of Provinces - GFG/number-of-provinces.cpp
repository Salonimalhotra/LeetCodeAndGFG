//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    void dfs(vector<vector<int>>&adj,int vertex,vector<bool>&visited,int V){
        visited[vertex]=true;
        for(int i=0;i<V;i++){
            if(i!=vertex && adj[vertex][i]==1 && visited[i]!=true){
                dfs(adj,i,visited,V);
            }
        }
        return;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int cnt=0;
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                dfs(adj,i,visited,V);
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends