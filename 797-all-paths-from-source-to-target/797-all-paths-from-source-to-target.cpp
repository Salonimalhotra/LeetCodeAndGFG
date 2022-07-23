#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    void dfs(int vertex,int dest,vector<bool>&visited,vector<vector<int>>&graph,vector<int>&path,vector<vector<int>>&ans){
         if(vertex==dest){
          path.push_back(dest);
          ans.push_back(path);
          path.pop_back();
          return;   
        }
        
        visited[vertex]=true;
        path.push_back(vertex);
        for(auto i:graph[vertex]){
            if(visited[i]!=true){
               dfs(i,dest,visited,graph,path,ans);     
            }           
        }
        visited[vertex]=false;
        path.pop_back();
        return;
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>ans;
        vector<int>path;
        vector<bool>visited(n,false);
        
        dfs(0,n-1,visited,graph,path,ans);
        return ans;        
    }
};