// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool helper(int V,int * colors, vector<int>adj[],int si){
        colors[si]=0;
        queue<int>q;
        q.push(si);
        while(q.size()!=0){
            int topNode=q.front();
            q.pop();
            for(int i=0;i<adj[topNode].size();i++){
                if(colors[adj[topNode][i]]==-1){
                    colors[adj[topNode][i]]=1-colors[topNode];
                    q.push(adj[topNode][i]);
                }
                else{
                    if(colors[topNode]==colors[adj[topNode][i]]){
                        return false;
                    }
                }
            }
        }
        return true;
        
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int * colors=new int [V];
	    for(int i=0;i<V;i++){
	        colors[i]=-1;
	    }
	    
	    for(int i=0;i<V;i++){
	        if(colors[i]==-1){
	            bool ans=helper(V,colors,adj,i);
	            if(ans==false){
	                return ans;
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