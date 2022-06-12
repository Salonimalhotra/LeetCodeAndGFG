// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
       int numTrailingZeroes(int x){
           int count=0;
        for(int i=5;i<=x;i*=5){
            count+=x/i;
         }
         return count;
       }
        int findNum(int n){
        //complete the function here
        //we are selecting low as 1 as if there are no leading zeroes then smallest number would be 5
        int low=1;
        int high=5*n;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            // cout<<mid<<endl;
            // cout<<numTrailingZeroes(mid)<<endl;
            if(numTrailingZeroes(mid)>=n){
                
                ans=mid;
                high=mid-1;
            }
            else if(numTrailingZeroes(mid)<n){
                low=mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends