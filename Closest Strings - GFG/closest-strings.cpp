//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int shortestDistance(vector<string> &s, string word1, string word2)
	{
		// Your code goes here
		int d1=0;
		int d2=0;
		int n=s.size();
		int ans=1e9;
		
		for(int i=0;i<n;i++){
		    if(s[i]==word1){
		        d1=i;
		    }
		    if(s[i]==word2){
		        d2=i;
		    }
		    
		    if(s[d1]==word1 and s[d2]==word2){
		        ans=min(ans, abs(d2-d1));
		    }
		}
		return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;

   		vector<string> s(n);
   		for(int i = 0; i < n; i++)
   			cin >> s[i];

   		string word1, word2;

   		cin >> word1 >> word2;
   		
   		Solution ob;

   		cout << ob.shortestDistance(s, word1, word2) << "\n";
   	}

    return 0;
}
// } Driver Code Ends