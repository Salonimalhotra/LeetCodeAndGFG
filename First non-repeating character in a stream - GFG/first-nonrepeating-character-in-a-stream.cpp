// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		   unordered_map<char,int>map;
		   vector<char>v;
		   queue<char>q;
		   string ans="";
		   for(int i=0;i<A.size();i++){
		       if(map[A[i]]==0){
		          q.push(A[i]);
		       }
		       map[A[i]]++;
		       bool check=false;
		       while(q.size()!=0 && check==false){
		           if(map[q.front()]>1){
		               q.pop();
		           }
		           else{
		               check=true;
		               break;
		           }
		       }
		       if(check==true){
		           ans.push_back(q.front());
		       }
		       else{
		           ans.push_back('#');
		       }
		   }
		   return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends