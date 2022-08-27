class Solution {
public:
    bool missingPos(vector<vector<char>>& board,int n,int &row,int &col){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='.'){
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
bool isSafeRow(vector<vector<char>>& board,int row,int n,char num){
    for(int i=0;i<board.size();i++){
        if(board[row][i]==num){
            return false;
        }
    
    }
    return true;
}

bool isSafeCol(vector<vector<char>>& board,int col,int n,char num){
    for(int i=0;i<board.size();i++){
        if(board[i][col]==num){
            return false;
        }
    
    }
    return true;
}
void BoxCoordinates(vector<vector<char>>& board,int row,int col,int &i,int &j,int n,char num){
   if(row>=0 && row<=2){
       i=0;
   }
   if(row>=3 && row<=5){
       i=3;
   }
    if(row>=6 && row<=8){
        i=6;
    }
    if(col>=0 && col<=2){
        j=0;
    }
    if(col>=3 && col<=5){
        j=3;
    }
    if(col>=6 && col<=8){
        j=6;
    }
    return;
}
bool isSafeBox(vector<vector<char>>& board,int row,int col,int n,char num){
    int i=0;
    int j=0;
    BoxCoordinates(board,row,col,i,j,n,num);
    for(int m=i;m<=i+2;m++){
        for(int k=j;k<=j+2;k++){
            if(board[m][k]==num){
                return false;
            }
        }
    }
    return true;
}

bool isSafe(vector<vector<char>>& board,int row,int col,int n,char num){
    bool option1=isSafeRow(board,row,n,num);
    bool option2=isSafeCol(board,col,n,num);
    bool option3=isSafeBox(board,row,col,n,num);
    if(option1==true && option2==true && option3==true){
        return true;
    }
    return false;
}
bool solve(vector<vector<char>>& board,int n){
    int row;
    int col;
    bool missPos=missingPos(board,n,row,col);
    if(missPos!=true){
        return true;
    }
    for(int i=1;i<=9;i++){         
        if(isSafe(board,row,col,n,i + '0')){
            board[row][col]=i+'0';
            if(solve(board,n)){
               return true;
            }
        }
        board[row][col]='.';        
    }
    return false;
}
    void solveSudoku(vector<vector<char>>& board) {
        bool smallAns=solve(board,board.size());
        return;
    }
};