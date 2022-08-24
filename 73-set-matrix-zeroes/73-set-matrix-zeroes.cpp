class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>s1(matrix.size(),-1);
        vector<int>s2(matrix[0].size(),-1);
        
        
        for(int i=0;i<matrix.size();i++){
           for(int j=0;j<matrix[0].size();j++){
               if(matrix[i][j]==0){
                   s1[i]=0;
                   s2[j]=0;
               }
           }
        }
        
        
        for(int i=0;i<matrix.size();i++){
         for(int j=0;j<matrix[0].size();j++){
              if(s1[i]==0 || s2[j]==0){
                  matrix[i][j]=0;
              }
         }
        }
        
        return;
    }
};