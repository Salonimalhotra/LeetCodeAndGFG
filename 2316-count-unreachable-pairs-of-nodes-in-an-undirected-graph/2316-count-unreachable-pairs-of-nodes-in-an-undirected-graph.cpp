class Solution {
public:
    void dfs(int n,vector<vector<int>>& adj,bool * visited,int &x,int sc){
        visited[sc]=true;
        x++;
        // for(int i=0;i<n;i++){
        //     if(visited[i]!=true && adj[sc][i]==1){
        //         dfs(n,adj,visited,x,i);
        //     }
        // }
        for(int i=0;i<adj[sc].size();i++){
            if(visited[adj[sc][i]]!=true){
                dfs(n,adj,visited,x,adj[sc][i]);
            }
        }
        return;
    }
    long long int helper(int n,vector<vector<int>>& adj){
       bool * visited=new bool[n];
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
      long long count=0;
       long long int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]!=true){
                int x=0;
                dfs(n,adj,visited,x,i);
                ans+=count*x;
                count+=x;
            }
        }
        return ans;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n,vector<int>());       
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        long long int ans=helper(n,adj);
        return ans;
        
    }
};