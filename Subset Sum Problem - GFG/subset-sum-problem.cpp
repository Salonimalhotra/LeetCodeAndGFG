// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int N=arr.size();
         bool**ans=new bool*[N+1];
        for(int i=0;i<=N;i++){
            ans[i]=new bool[sum+1];
            
        }
        
        for(int j=0;j<=sum;j++){
            ans[0][j]=false;
        }
        
        for(int i=0;i<=N;i++){
            ans[i][0]=true;
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j){
                    ans[i][j]=ans[i-1][j] || ans[i-1][j-(arr[i-1])];
                }
                else if(arr[i-1]>j){
                    ans[i][j]=ans[i-1][j];
                }
            }
        }
        return ans[N][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends