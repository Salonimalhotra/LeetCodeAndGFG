class Solution {
public:
    bool helper(vector<vector<char>>& board,vector<vector<bool>>& vis,string word,int row,int col){
       if(word.size()==0) return true;
       if(row>=board.size() || row<0 || col>board[0].size() || col<0) return false;
       if(vis[row][col]==true) return false;
       if(board[row][col]!=word[0]) return false;
       vis[row][col]=true;
       bool option1=helper(board,vis,word.substr(1),row+1,col);
       bool option2=helper(board,vis,word.substr(1),row-1,col);
       bool option3=helper(board,vis,word.substr(1),row,col+1);
       bool option4=helper(board,vis,word.substr(1),row,col-1);
       if(option1==true || option2==true || option3==true || option4==true) return true;
       vis[row][col]=false;
       return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
          vector<vector<bool>>vis(board.size(),vector<bool>(board[0].size(),false));
          for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
              if(board[i][j]==word[0]){
                bool smallans=helper(board,vis,word,i,j);
                if(smallans)return true;
              }              
            }
          }
      return false;
    }
};