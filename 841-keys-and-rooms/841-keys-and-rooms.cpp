#include<vector>
class Solution {
public:
    
    void dfs(int v,vector<bool>&visited,vector<vector<int>>&rooms){
        visited[v]=true;
        for(auto i:rooms[v]){
            if(v!=i && visited[i]!=true){
                dfs(i,visited,rooms);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        dfs(0,visited,rooms);
        for(int i=0;i<n;i++){
            if(visited[i]!=true){
                return false;
            }
        }
        return true;
    }
};