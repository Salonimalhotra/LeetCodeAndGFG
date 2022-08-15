class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>>v(grid.size()-2,vector<int>(grid.size()-2,0));
        for(int i=0;i<n-2;i++){         
            for(int j=0;j<n-2;j++){
                int maxElement=INT_MIN; 
                
                for(int x=i;x<=i+2;x++){
                    for(int y=j;y<=j+2;y++){
                        maxElement=max(maxElement,grid[x][y]);
                    }
                }
               v[i][j]=maxElement;
            }
            
        }
        return v;        
    }
};