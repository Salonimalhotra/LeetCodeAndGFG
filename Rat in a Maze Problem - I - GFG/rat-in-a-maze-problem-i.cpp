// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void helper(vector<vector<int>> &m, int n,int row,int col,string x,vector<vector<bool>>&visited,vector<string>&ans){
        if(row<0 || col<0 || row>=n || col>=n){
            return;
        }
        
        if(m[row][col]==0){
            return;
        }
        
        if(row==n-1 && col==n-1){
            ans.push_back(x);
            return;
        }
        
        if(visited[row][col]==true){
            return;
        }
        
        visited[row][col]=true;
        helper(m,n,row,col+1,x+'R',visited,ans);
        helper(m,n,row+1,col,x+'D',visited,ans);
        helper(m,n,row,col-1,x+'L',visited,ans);
        helper(m,n,row-1,col,x+'U',visited,ans);
        visited[row][col]=false;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        vector<string>ans;
        string x="";
        helper(m,n,0,0,x,visited,ans);
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