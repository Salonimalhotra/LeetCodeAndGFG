class Solution {
public:
    int index(vector<vector<int>>& grid,int row,int col){
        int start=0;
        int end=col-1;
        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(grid[row][mid]<0){
                ans=mid;
                end=mid-1;
            }
            else if(grid[row][mid]>=0){
                start=mid+1;
            }
        }
        return ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int totalAns=0;
        for(int i=0;i<grid.size();i++){
            int positive=index(grid,i,grid[0].size());
            if(positive!=-1){
            totalAns+=grid[0].size()-positive;
            }
        }
        return totalAns;
    }
};