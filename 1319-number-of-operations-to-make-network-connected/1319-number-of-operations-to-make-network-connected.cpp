#include<vector>
class Solution {
public:
    void helper(int vertex,bool * visited,vector<vector<int>>&adj){
      
        visited[vertex]=true;
        // vertices++;
        
        for(auto i:adj[vertex]){
            if(visited[i]!=true){
                // edges++;
                helper(i,visited,adj);
                
            }
            else if(visited[i]==true){
                // edges++;
                continue;
            }
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //create and adj list basically
        vector<vector<int>>adj(n,vector<int>());
        for(int i=0;i<connections.size();i++){
             int firstv=connections[i][0];
             int secondv=connections[i][1];
             adj[firstv].push_back(secondv);
             adj[secondv].push_back(firstv);
        }
        
        //
        bool * visited=new bool[n];
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]!=true){
                 ans++;
                helper(i,visited,adj);
               
            }
        }
        if(connections.size()<n-1){
            return -1;
        }
        return ans-1;
        
    }
};