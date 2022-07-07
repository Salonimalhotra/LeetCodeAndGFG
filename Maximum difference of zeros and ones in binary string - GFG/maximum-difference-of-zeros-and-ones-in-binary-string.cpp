// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int ans=0;
	    int maxAns=INT_MIN;
	    for(int i=0;i<S.size();i++){
	        if(S[i]=='1'){
	            ans--;
	        }
	        else if(S[i]=='0'){
	            ans++;
	        }
	        
	        if(ans>maxAns){
	            maxAns=ans;
	        }
	        if(ans<0){
	            ans=0;
	        }
	    }
	    return maxAns;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends