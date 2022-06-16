// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void helper(string S,string output,vector<string>&finalans){
	        if(S.size()==0){
	            finalans.push_back(output);
	            return;
	        }
	        for(int i=0;i<S.size();i++){
	            helper(S.substr(0,i)+S.substr(i+1),output+S[i],finalans);
	        }
	        return;
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    	vector<string>finalans;
		    	string output="";
		    	helper(S,output,finalans);
		    	set<string>s;
		    	for(auto i:finalans){
		    	    s.insert(i);
		    	}
		    	finalans.clear();
		    	for(auto i:s){
		    	    finalans.push_back(i);
		    	}
		    	return finalans;
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