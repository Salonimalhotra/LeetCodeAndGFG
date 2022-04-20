// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
   bool findEmptyPosition(int board[9][9],int &row,int &col,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==0){
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
void findingBoxCoordinates(int board[9][9],int row,int col,int &i,int &j,int num,int n){
    if(row>=0 && row<=2){
        i=0;        
    } 
    else if(row>=3 && row<=5){
        i=3;
    }
    else if(row>=6 && row<=8){
        i=6;
    }
    
    if(col>=0 && col<=2){
        j=0;
    }
    else if(col>=3 && col<=5){
        j=3;
    }
    else if(col>=6 && col<=8){
        j=6;
    }
    return;
}
bool isSafeInRow(int board[9][9],int row,int col,int num,int n){
    bool ans=true;
    for(int i=0;i<n;i++){
        if(board[row][i]==num){
            ans=false;
            break;
        }
    }
    return ans;
}
bool isSafeInCol(int board[9][9],int row,int col,int num,int n){
    bool ans=true;
    for(int i=0;i<n;i++){
        if(board[i][col]==num){
            ans=false;
            break;
        }
    }
    return ans;
}
bool isSafeInBox(int board[9][9],int row,int col,int num,int n){
    int i;
    int j;
    findingBoxCoordinates(board,row,col,i,j,num,n);
    bool ans=true;
    for(int x=i;x<i+3;x++){
        for(int y=j;y<j+3;y++){
            if(board[x][y]==num){
                ans=false;
            }
        }
    }
    return ans;
}
bool isSafe(int board[9][9],int row,int col,int num,int n){
    
    bool option1=isSafeInRow(board,row,col,num,n);
    bool option2=isSafeInCol(board,row,col,num,n);
    bool option3=isSafeInBox(board,row,col,num,n);
    if(option1 && option2 && option3){
        return true;
    }
    else{
        return false;
    }
}
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
         int row;
         int col;
        if(!findEmptyPosition(grid,row,col,9)){
        return true;
       }
    
        for(int num=1;num<=9;num++){
            if(isSafe(grid,row,col,num,9)==true){
                grid[row][col]=num;
                if(SolveSudoku(grid)){
                    return true;
                }
            }        
             grid[row][col]=0;
        }
         
        
    
    return false;
    
}
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
        return;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends