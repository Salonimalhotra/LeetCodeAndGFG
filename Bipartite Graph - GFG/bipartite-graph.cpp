// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool helper(int V,int si,vector<int>adj[],int * colors){
        for(int i=0;i<adj[si].size();i++){
            if(colors[adj[si][i]]==-1){
                colors[adj[si][i]]=1-colors[si];
                bool ans=helper(V,adj[si][i],adj,colors);
                if(ans==false){
                    return false;
                }
                else{
                    continue;
                }
            }
            else{
                if(colors[adj[si][i]]==colors[si]){
                    return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int * colors=new int[V];
	    for(int i=0;i<V;i++){
	        colors[i]=-1;
	    }
	    
	    for(int i=0;i<V;i++){
	        if(colors[i]==-1){
	            colors[i]=1;
	            bool ans=helper(V,i,adj,colors);
	            if(ans==false){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends