// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
bool compare(val p1,val p2){
    return p1.second<p2.second;
      

}
int maxChainLen(struct val p[],int n)
{
//Your code here
sort(p,p+n,compare);
  int dp[n];
  dp[0]=1;
  for(int i=1;i<n;i++){
      dp[i]=1;
      for(int j=i-1;j>=0;j--){
          if(p[j].second<p[i].first){
              dp[i]=max(dp[i],dp[j]+1);
          }
      }
  }
  
  int best_ans=1;
  for(int i=0;i<n;i++){
      if(best_ans<dp[i]){
          best_ans=dp[i];
      }
  }
  return best_ans;
}