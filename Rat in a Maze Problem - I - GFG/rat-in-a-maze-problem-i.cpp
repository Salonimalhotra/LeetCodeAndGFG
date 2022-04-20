// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void ratInMazeHelper(vector<vector<int>>&m,vector<vector<int>>&sol,int n,vector<string>&ans,int row,int col,char direction,string &x){
        if(row==n-1 && col==n-1){
             sol[row][col]=1;
            x.push_back(direction);
            if(m[row][col]!=0){
                 ans.push_back(x);
            }
           
            sol[row][col]=0;
            x.pop_back();
            return;
        }
        if(row>=n || col>=n || row<0 || col<0 || m[row][col]==0 || sol[row][col]==1){
            return;
        }
        
        sol[row][col]=1;
        if(row!=0 || col!=0){
             x.push_back(direction);
        }
        ratInMazeHelper(m,sol,n,ans,row+1,col,'D',x);
        ratInMazeHelper(m,sol,n,ans,row-1,col,'U',x);
        ratInMazeHelper(m,sol,n,ans,row,col+1,'R',x);
        ratInMazeHelper(m,sol,n,ans,row,col-1,'L',x);
        sol[row][col]=0;
         if(row!=0 || col!=0){
          x.pop_back();
        }
        return;
    }
    void ratInMaze(vector<vector<int>>&m,vector<vector<int>>&sol,int n,vector<string>&ans){
        string x;
        ratInMazeHelper(m,sol,n,ans,0,0,'A',x);
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>>sol;
        for(int i=0;i<n;i++){
            vector<int>sol1;
            for(int j=0;j<n;j++){
                sol1.push_back(0);
            }
            sol.push_back(sol1);
        }
        ratInMaze(m,sol,n,ans);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends