#include<vector>
class Solution {
public:
        void dfs(vector<vector<char>>&grid,int sr,int sc,int m,int n, vector<vector<bool>>&visited){
        if(sr<0 || sc<0 || sr>=m || sc>=n){
            return;
        }
        
        if(grid[sr][sc]=='0'){
            return;
        }    
            
        if(visited[sr][sc]==true){
            return;
        }        
     
        visited[sr][sc]=true;
        dfs(grid,sr+1,sc,m,n,visited);
        dfs(grid,sr-1,sc,m,n,visited);
        dfs(grid,sr,sc-1,m,n,visited);
        dfs(grid,sr,sc+1,m,n,visited);
        
        return;
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;   
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j,m,n,visited);
                }
            }
        }
        return count;
    }
};