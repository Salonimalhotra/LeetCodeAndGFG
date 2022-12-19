class Solution {
public:
    bool helper(vector<vector<int>>&adj,int firstvertex,int destination,vector<bool>&vis){
      if(firstvertex==destination){
        return true;
      }
      vis[firstvertex]=true;
      for(auto i:adj[firstvertex]){
        if(vis[i]!=true){
        bool check=helper(adj,i,destination,vis);
        if(check==true) return true;
        }
      }
      return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
          int firstv=edges[i][0];
          int secondv=edges[i][1];
          adj[firstv].push_back(secondv);
          adj[secondv].push_back(firstv);
        }
        vector<bool>vis(n,false);
        return helper(adj,source,destination,vis);
        
    }
};