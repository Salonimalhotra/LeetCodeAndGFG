//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>>adj(N,vector<int>());
	    for(int i=0;i<prerequisites.size();i++){
	        int firstv=prerequisites[i].first;
	        int secondv=prerequisites[i].second;
	        adj[secondv].push_back(firstv);
	    }
	    
	    vector<int>indegree(N,0);
	    for(int i=0;i<N;i++){
	        for(auto j:adj[i]){
	            indegree[j]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<indegree.size();i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    int cnt=0;
	    while(q.size()!=0){
	        int topElement=q.front();
	        q.pop();
	        cnt++;
	        
	        for(auto j:adj[topElement]){
	            indegree[j]--;
	            if(indegree[j]==0){
	                q.push(j);
	            }
	        }
	    }
	    if(cnt==N) return true;
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends