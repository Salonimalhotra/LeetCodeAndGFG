class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int rows=n;
        int cols=n;
        int rowStart=0;
        int rowEnd=n-1;
        int colStart=0;
        int colEnd=n-1;
        int k=1;
        int totalElements=n * n;
        int cntElements=0;
        while(cntElements<totalElements){
            for(int j=colStart;j<=colEnd;j++){
                ans[rowStart][j]=k;
                k++;
                cntElements++;
            }
            
            rowStart++;
            
            for(int i=rowStart;i<=rowEnd;i++){
                ans[i][colEnd]=k;
                k++;
                cntElements++;
            }
            
            colEnd--;
            
            for(int j=colEnd;j>=colStart;j--){
                ans[rowEnd][j]=k;
                k++;
                cntElements++;
            }
            
            rowEnd--;
            
            for(int i=rowEnd;i>=rowStart;i--){
                ans[i][colStart]=k;
                k++;
                cntElements++;
            }
            
            colStart++;
        }
        
        return ans;
    }
};