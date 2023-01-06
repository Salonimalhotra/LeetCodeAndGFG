//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int isPossible (string S)
{
    // your code here
    unordered_map<char,int>mp;
    for(int i=0;i<S.size();i++){
        mp[S[i]]++;
    }
    bool flag=false;
    for(auto i:mp){
        if(i.second%2==0){
            continue;
        }
        else{
            if(flag) return 0;
            else{
                flag=true;
            }
        }
    }
    return 1;
}