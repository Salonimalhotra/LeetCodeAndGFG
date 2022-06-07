// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countOfLessThanEqualTo(vector<vector<int>> &matrix,int r,int c,int i,int mid){
        int low=0;
        int high=c-1;
        while(low<=high){
            int md=(low+(high-low)/2);
            if(matrix[i][md]<=mid){
                low=md+1;
            }
            else{
                high=md-1;
            }
        }
        return low;
    }
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here          
        //efficient approach :-
        int low=0;
        int high=1e9;
        while(low<=high){
            int mid=(low+(high-low)/2);
            int cnt=0;
            for(int i=0;i<r;i++){
                cnt+=countOfLessThanEqualTo(matrix,r,c,i,mid);
            }
            if(cnt<=(r*c)/2){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends