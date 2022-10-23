//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void helper(int N,vector<pair<int,int>>adj[],vector<bool>&vis, stack<int>&st,int vertex){
        vis[vertex]=true;
        
        for(auto i:adj[vertex]){
            if(vis[i.first]!=true){
                helper(N,adj,vis,st,i.first);
            }
        }
        
        st.push(vertex);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int>visited(N,false);
        vector<pair<int,int>>adj[N];
        
        for(int i=0;i<edges.size();i++){
            int firstv=edges[i][0];
            int secondv=edges[i][1];
            int weight=edges[i][2];
            adj[firstv].push_back(make_pair(secondv,weight));
        }
        
        stack<int>st;
        vector<bool>vis(N,false);
        vector<int>dist(N,1e9);
        
        for(int i=0;i<vis.size();i++){
            if(vis[i]==false){
                helper(N,adj,vis,st,i);
            }
        }
        
        dist[0]=0;
        
        while(st.size()!=0){
            int topElement=st.top();
            st.pop();
            for(auto j:adj[topElement]){
                if(dist[j.first]>dist[topElement] + j.second){
                    dist[j.first]=dist[topElement] + j.second;
                }
            }
        }
        for(int i=0;i<dist.size();i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
        }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends