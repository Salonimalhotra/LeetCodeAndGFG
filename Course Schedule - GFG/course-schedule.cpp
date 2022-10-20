//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int>ans;
        vector<vector<int>>adj(N,vector<int>());
	    for(int i=0;i<prerequisites.size();i++){
	        int firstv=prerequisites[i][0];
	        int secondv=prerequisites[i][1];
	        adj[secondv].push_back(firstv);
	    }
	    
	    vector<int>indegree(N,0);
	    for(int i=0;i<N;i++){
	        for(auto j:adj[i]){
	            indegree[j]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<indegree.size();i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(q.size()!=0){
	        int topElement=q.front();
	        q.pop();
	        ans.push_back(topElement);
	      
	        
	        for(auto j:adj[topElement]){
	            indegree[j]--;
	            if(indegree[j]==0){
	                q.push(j);
	            }
	        }
	    }
	    if(ans.size()==N)return ans;
	    return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends