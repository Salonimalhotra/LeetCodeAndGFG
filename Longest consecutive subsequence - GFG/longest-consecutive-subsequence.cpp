// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_map<int,int>mp;
      for(int i=0;i<N;i++){
          mp[arr[i]]++;
      }
      int ans=INT_MIN;
      for(int i=0;i<N;i++){
          if(mp.find(arr[i]-1)==mp.end()){
              int count=0;
              int x=arr[i];
              while(mp.find(x)!=mp.end()){
                  count++;
                  x=x+1;
              }
              ans=max(count,ans);
          }
      }
      return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends