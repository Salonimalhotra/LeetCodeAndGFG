#include<vector>
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int rows=matrix.size();
        int cols=matrix[0].size();
        int totalElements=rows*cols;
        int numberElements=0;
        int rowStart=0;
        int rowEnd=rows-1;
        int colStart=0;
        int colEnd=cols-1;
        while(numberElements<totalElements){
            //print the firstRow from left to right;
            for(int i=colStart;i<=colEnd && numberElements<totalElements;i++){
                ans.push_back(matrix[rowStart][i]);
                numberElements++;
            }
            rowStart++;
            //print lastCol from top to bottom
            for(int i=rowStart;i<=rowEnd  && numberElements<totalElements;i++){
                ans.push_back(matrix[i][colEnd]);
                numberElements++;
            }
            colEnd--;
            //print last row from right to left
            for(int i=colEnd;i>=colStart  && numberElements<totalElements;i--){
                ans.push_back(matrix[rowEnd][i]);
                  numberElements++;
            }
            rowEnd--;
            //print first col from bottom to top
            
            for(int i=rowEnd;i>=rowStart && numberElements<totalElements;i--){
                 ans.push_back(matrix[i][colStart]);
                 numberElements++;            
            }
            colStart++;
        }
         return ans;
    }
   
};