// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
   bool dfs(int vertex,int V,int * colours,vector<int>adj[]){
    //   colours[vertex]=0;
    //   queue<int>pending;
    //   pending.push(vertex);
    //   while(pending.size()!=0){
    //       int top=pending.front();
    //       pending.pop();
    //       for(auto i:adj[top]){
    //           if(colours[i]!=-1){
    //               if(colours[i]==colours[top]){
    //                   return false;
    //               }
    //               else{
    //                   continue;
    //               }
    //           }
    //           else{
    //               colours[i]=1-colours[top];
    //               pending.push(i);
    //           }
    //       }
    //   }
    //return true;
      for(auto i:adj[vertex]){
          if(colours[i]!=-1){
              if(colours[i]==colours[vertex]){
                  return false;
              }
          }
          else{
              colours[i]=1-colours[vertex];
              bool ans=dfs(i,V,colours,adj);
              if(!ans){
                  return false;
              }
          }
      }
    return true;    
       
   }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int * colours=new int[V];
	    for(int i=0;i<V;i++){
	        colours[i]=-1;
	    }
	    
	    for(int i=0;i<V;i++){
	        if(colours[i]==-1){
	            colours[i]=1;
	            if(!dfs(i,V,colours,adj)){
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