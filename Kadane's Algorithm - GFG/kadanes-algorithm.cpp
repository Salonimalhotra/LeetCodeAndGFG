// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long ans=INT_MIN;
        long long sum=0;
        for(int i=0;i<n;i++){
            //first add the current element to sum
            sum+=arr[i];
            if(i==0){
                ans=sum;
            }
            else{
                 ans=max(sum,ans);
            }
            
            //if sum is negative then set sum to 0 as we would be starting fresh sum from the next subarray as current negative is only decreasing the sum further in the array
            if(sum<0){
                sum=0;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends