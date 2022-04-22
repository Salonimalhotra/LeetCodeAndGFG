// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    int helper(string S,vector<string>&ans){
	        if(S.size()==0){
	            string x="";
	            ans.push_back(x);
	            return 1;
	        }
	        int k=0;
	        for(int i=0;i<S.size();i++){
	            char firstchar=S[i];
	            vector<string>ans1;
	            int smalloutputSize=helper(S.substr(0,i)+S.substr(i+1,S.size()),ans1);
	            for(int j=0;j<smalloutputSize;j++){
	                string x="";
	                x.push_back(firstchar);
	                x.append(ans1[j]);
	                ans.push_back(x);
	                k++;
	            }
	        }
	        return k;
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    string output="";
		    vector<string>ans;
		    int size=helper(S,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends