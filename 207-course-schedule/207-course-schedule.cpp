#include<bits/stdc++.h>
#include<vector>
class Solution {
public:
 
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses,vector<int>());
        vector<int>indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            int fv=prerequisites[i][0];
            int sv=prerequisites[i][1];
            adj[sv].push_back(fv);        
            indegree[fv]++;
       }
        
       queue<int>q;
        for(int i=0;i<indegree.size();i++){
           if(indegree[i]==0){
               q.push(i);
           }
        }
        int cnt=0;
        while(q.size()!=0){
            int top=q.front();
            q.pop();
            cnt++;
            for(auto i:adj[top]){
                indegree[i]--;
                if(indegree[i]==0){
                  q.push(i);
                }
            }
        }
        
        if(cnt==numCourses){
            return true;
        }
        else{
            return false;
        }
        
        
    }
};