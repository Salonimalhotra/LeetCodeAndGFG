class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       // int i=0;
       // int j=matrix[0].size()-1;
       //  while(i>=0 && j>=0 && i<matrix.size() && j<matrix[0].size()){
       //      if(matrix[i][j]==target){
       //          return true;
       //      }
       //      else if(matrix[i][j]>target){
       //          j--;
       //      }
       //      else if(matrix[i][j]<target){
       //          i++;
       //      }
       //  }
       //  return false;
        
        int rows=matrix.size();
        int cols=matrix[0].size();
        int i=0;
        int j=rows*cols -1;
        int mid=i+(j-i)/2;
        while(i<=j){
            //as we know when stored in a linear order the element is store like :- i*c+j;
            //therefore to get to know the col index would be 
            int element=matrix[mid/cols][mid%cols];
            if(element==target){
                return 1;
            }
            else if(element<target){
                i=mid+1;
            }
            else if(element>target){
                j=mid-1;
            }
            mid=i+(j-i)/2;
        }
        return 0;
    }
};