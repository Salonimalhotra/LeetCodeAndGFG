#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
class Solution {
public:
    void dfs(int i,int par,vector<bool>&vis,vector<int>&disc,vector<int>&low,vector<vector<int>>&adj,int &timer,vector<vector<int>>&ans){
        vis[i]=true;
        
        disc[i]=low[i]=timer++;
        
        for(auto neigh:adj[i]){
            if(neigh==par){
                continue;
            }
            else if(vis[neigh]!=true){
                dfs(neigh,i,vis,disc,low,adj,timer,ans);
                
                //updating our low with child node's low if there is a backedge of lows neighbour
                low[i]=min(low[i],low[neigh]);
                //
                
                if(low[neigh]>disc[i]){
                vector<int> res;
                res.push_back(i);
                res.push_back(neigh);
                ans.push_back(res);
                }
            }
            else{
                //back edge ka case , as it is already visited neighbour and its not a parent ,therfore it means it was discovered early and hence we can also update low time of our current node to disc[neighbour] if disc[neigbour] is less than our low
                low[i]=min(low[i],disc[neigh]);                
            }
        }       
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n,vector<int>());
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<int>disc(n,-1);
        vector<int>low(n,-1);
        int par=-1;
        int timer=0;
        vector<bool>vis(n,false);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,par,vis,disc,low,adj,timer,ans);
            }
        }
        return ans;
    }
};