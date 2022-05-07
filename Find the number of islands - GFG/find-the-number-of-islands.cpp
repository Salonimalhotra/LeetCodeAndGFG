// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid,int row,int col,int n,int m,bool ** visited){
        if(row<0 || col<0 || row>=n || col>=m){
            return;
        }
        if(visited[row][col]==true){
            return;
        }
        if(grid[row][col]=='0'){
            return;
        }
        visited[row][col]=true;
        
        dfs(grid,row-1,col,n,m,visited);
        dfs(grid,row-1,col+1,n,m,visited);
        dfs(grid,row,col+1,n,m,visited);
        dfs(grid,row+1,col+1,n,m,visited);
        dfs(grid,row+1,col,n,m,visited);
        dfs(grid,row+1,col-1,n,m,visited);
        dfs(grid,row,col-1,n,m,visited);    
        dfs(grid,row-1,col-1,n,m,visited);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        bool** visited=new bool*[n];
        for(int i=0;i<n;i++){
            visited[i]=new bool[m];
            for(int j=0;j<m;j++){
                visited[i][j]=false;
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]!=true && grid[i][j]!='0'){
                    dfs(grid,i,j,n,m,visited);
                    count++;
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends