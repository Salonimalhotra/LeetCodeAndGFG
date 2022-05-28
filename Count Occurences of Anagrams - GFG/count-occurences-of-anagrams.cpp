// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
#include<unordered_map>
#include<bits/stdc++.h>
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    unordered_map<char,int>map;
	    int k=pat.size();
	    int i=0;
	    int j=0;
	    int count=0;
	    int ans=0;
	    for(int i=0;i<pat.size();i++){
	        map[pat[i]]++;
	        if(map[pat[i]]==1){
	            count++;
	        }
	    }
	    while(j<txt.size()){
	        
	        if(map.count(txt[j])>0){
	                map[txt[j]]--;
	                if(map[txt[j]]==0){
	                    count--;
	                }
	            }
	            
	        if(j-i+1<k){
	            j++;
	        }
	        
	        else if(j-i+1==k){
	            
	            if(count==0){
	                ans++;
	            }
	            
	            if(map.count(txt[i])>0){
	                map[txt[i]]++;
	                if(map[txt[i]]==1){
	                    count++;
	                }
	            }
	            
	            i++;
	            j++;
	            
	        }
	    }
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends