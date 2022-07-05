// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
#include<vector>
class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      //Code here
      vector<int>ans(a.size(),0);
      for(int i=0;i<a.size();i++){
          if(i==0){
              ans[i]=a[i];
          }
          else{
              int option1=ans[i-1]+a[i];
              int option2=a[i];
              if(option1<option2){
                  ans[i]=option1;
              }
              else if(option2<option1){
                  ans[i]=option2;
              }
          }
      }
      
      int minAns=INT_MAX;
      for(int i=0;i<ans.size();i++){
          if(ans[i]<minAns){
              minAns=ans[i];
          }
      }
      return minAns;
  }
};


// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}  // } Driver Code Ends