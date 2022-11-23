class Solution {
public:
    bool safeRow(vector<vector<char>>&board,int i,int j){
        for(int rows=0;rows<board.size();rows++){
            if(board[rows][j]==board[i][j] && rows!=i){
                return false;
            }
        }
        return true;
    }
    
     bool safeCol(vector<vector<char>>&board,int i,int j){
        for(int cols=0;cols<board[0].size();cols++){
            if(board[i][cols]==board[i][j] && cols!=j ){
                return false;
            }
        }
        return true;
    }
    
    bool safeBox(vector<vector<char>>&board,int i,int j){
        int start_x;
        int end_x;     
        
        if(i>=0 && i<=2){
            start_x=0;
            end_x=2;
        }
        
        else if(i>=3 && i<=5){
            start_x=3;
            end_x=5;
        }
        
        else if(i>=6 && i<=8){
            start_x=6;
            end_x=8;
        }
        
        int start_y;
        int end_y;
          
        
        if(j>=0 && j<=2){
            start_y=0;
            end_y=2;
        }
        
        else if(j>=3 && j<=5){
            start_y=3;
            end_y=5;
        }
        
        else if(j>=6 && j<=8){
            start_y=6;
            end_y=8;
        }
        
        
        for(int k=start_x;k<=end_x;k++){
            for(int m=start_y;m<=end_y;m++){
                if(board[k][m]==board[i][j] && k!=i && m!=j){
                    return false;
                }
            }
        }        
        return true;        
    }
    
    bool check(vector<vector<char>>&board,int i,int j){
        bool ans=safeRow(board,i,j) && safeCol(board,i,j)&& safeBox(board,i,j);
        return ans;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                      bool help=check(board,i,j);
                      if(help==true){
                          continue;
                      }
                    else{
                        return false;
                    }
                }  
              }
            
           }
            return true;
    }
};