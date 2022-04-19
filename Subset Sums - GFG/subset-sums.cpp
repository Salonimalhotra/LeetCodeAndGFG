// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
   int helper(vector<int>arr,int N,vector<int>&outputArr){
       if(N==0){
           outputArr.push_back(0);
           return 1;
       }
       vector<int>smallInput;
       for(int i=1;i<arr.size();i++){
           smallInput.push_back(arr[i]);
       }
       int outputSize=helper(smallInput,N-1,outputArr);
       for(int i=0;i<outputSize;i++){
           int x=outputArr[i]+arr[0];
           outputArr.push_back(x);
       }
       return 2*outputSize;
   }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>outputArr;
        int finalAns=helper(arr,N,outputArr);
        return outputArr;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends