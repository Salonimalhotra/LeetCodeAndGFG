class Solution {
public:
    void dfs(vector<vector<int>>&image,int sr,int sc,int m,int n,int color, vector<vector<bool>>&visited,int target){
        if(sr<0 || sc<0 || sr>=m || sc>=n){
            return;
        }
        
        if(image[sr][sc]!=color){
            return;
        }
        if(visited[sr][sc]==true){
            return;
        }
        
        image[sr][sc]=target;
        visited[sr][sc]=true;
        dfs(image,sr+1,sc,m,n,color,visited,target);
        dfs(image,sr-1,sc,m,n,color,visited,target);
        dfs(image,sr,sc-1,m,n,color,visited,target);
        dfs(image,sr,sc+1,m,n,color,visited,target);
        
        return;
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
           int m=image.size();
           int n=image[0].size();
           vector<vector<bool>>visited(m,vector<bool>(n,false));
           dfs(image,sr,sc,m,n,image[sr][sc],visited,color);
           return image;           
    }
};