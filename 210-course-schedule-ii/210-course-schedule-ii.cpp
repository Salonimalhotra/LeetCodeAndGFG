#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    // void topoSort(int vertex,vector<int>&topo,vector<bool>&visited,vector<vector<int>>&adj){
    //     visited[vertex]=true;       
    //     for(auto i:adj[vertex]){
    //        if(visited[i]!=true){
    //            topoSort(i,topo,visited,adj);
    //        }     
    //     }
    //     topo.push_back(vertex);
    //     return;
    // }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();i++){
            int fv=prerequisites[i][0];
            int sv=prerequisites[i][1];
            adj[sv].push_back(fv);
        }
        
        vector<int>topo;        
        vector<int>indegree(numCourses,0);
        queue<int>q;
        for(int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][0]]++;
        }
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;        
        while(q.size()!=0){
            int top=q.front();
            q.pop();
            topo.push_back(top);
            cnt++;
            for(int i:adj[top]){
                 indegree[i]--;
                 if(indegree[i]==0){
                     q.push(i);
                 }
            }
        }
        
        if(cnt==numCourses){
            return topo;
        }
        else{
            vector<int>ans;
            return ans;
        }       
        
    }
};