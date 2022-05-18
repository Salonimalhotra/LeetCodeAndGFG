// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here      
        vector<long long int>left(n,0);
        left[0]=1;
        for(int i=1;i<n;i++){
            left[i]=nums[i-1]*left[i-1];
        }
        
        vector<long long int>right(n,0);
        right[n-1]=1;
        for(int j=n-2;j>=0;j--){
            right[j]=nums[j+1]*right[j+1];
        }
        
        vector<long long int>finalAns(n,0);
       for(int i=0;i<n;i++){
           finalAns[i]=left[i]*right[i];
       }
        return finalAns;
    }
    
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends