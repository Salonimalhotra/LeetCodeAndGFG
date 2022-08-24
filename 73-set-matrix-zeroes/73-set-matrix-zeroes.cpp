class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>>helper=matrix;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<cols;k++){
                        helper[i][k]=0;
                    }
                    
                    for(int m=0;m<rows;m++){
                        helper[m][j]=0;
                    }
                }
            }
        }
        matrix=helper;
        return ;
    }
};