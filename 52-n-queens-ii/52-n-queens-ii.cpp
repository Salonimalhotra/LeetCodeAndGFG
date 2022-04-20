class Solution {
public:
   bool isPossible(int **output,int row,int col,int n){
    //same col
    for(int i=row-1;i>=0;i--){
        if(output[i][col]==1){
            return false;
        }
    }
    //leftDiagonal check
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(output[i][j]==1){
            return false;
        }
    }
    
    //right diagonal check
     for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(output[i][j]==1){
            return false;
        }
    }
    
    return true;   
}
void placeNQueensHelper(int **output,int row,int n,int &ans){
    if(row==n){
        ans+=1;
        return;
    }
    
    for(int j=0;j<n;j++){
        if(isPossible(output,row,j,n)){
            output[row][j]=1;
            placeNQueensHelper(output,row+1,n,ans);
            output[row][j]=0;
        }
    }
}
void placeNQueens(int **output,int n,int &ans){
    placeNQueensHelper(output,0,n,ans);
}
    int totalNQueens(int n) {
        int ** output=new int*[n];
    for(int i=0;i<n;i++){
      output[i]=new int[n];
        for(int j=0;j<n;j++){
            output[i][j]=0;
        }
    }
        int ans=0;
      placeNQueens(output,n,ans);
        return ans;
    }
};