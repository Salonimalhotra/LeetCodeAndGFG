//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include<cmath>
#include<bits/stdc++.h>
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    int powerset=pow(2,s.size());
		    int n=s.size();
		    for(int i=0;i<powerset;i++){
		        string ans1="";
		        for(int j=0;j<s.size();j++){
		            int mask=1<<j;
		            if(i & mask){
		                ans1.push_back(s[j]);
		            }
		        }
		        if(ans1.size()!=0)ans.push_back(ans1);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends