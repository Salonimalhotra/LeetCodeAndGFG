// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int Maximize(int a[],int n)
    {
        // Complete the function
        long long int mod=pow(10,9)+7;
        sort(a,a+n);
        long long int  ans=0;
        for(int i=0;i<n;i++){
            ans+=(i%mod)*(a[i]%mod);
            ans=ans%mod;
        }
        return ans%mod;
    }
};

// { Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}  // } Driver Code Ends