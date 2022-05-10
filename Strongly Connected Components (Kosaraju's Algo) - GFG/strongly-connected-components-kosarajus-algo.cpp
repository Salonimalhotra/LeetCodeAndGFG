// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#include<stack>
#include<vector>

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void topoSort(stack<int>&S,int src,vector<int>adj[],bool * visited){
	    visited[src]=true;
	    for(int i=0;i<adj[src].size();i++){
	        if(visited[adj[src][i]]!=true){
	            topoSort(S,adj[src][i],adj,visited);
	        }
	        
	    }
	    S.push(src);
	    return;
	}
	void transpose_graph(vector<int>adj[],vector<int>s[],int V){
	 
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            int second_vertex=adj[i][j];
	            s[second_vertex].push_back(i);
	        }
	    }
	   return;
	}
	void dfs_traversal(vector<int>s[],bool * visited1,int src){
	    visited1[src]=true;
	    for(int i=0;i<s[src].size();i++){
	        if(visited1[s[src][i]]!=true){
	            dfs_traversal(s,visited1,s[src][i]);
	        }
	    }
	    return;
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        bool * visited=new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        stack<int>s1;
        topoSort(s1,0,adj,visited);
        for(int i=0;i<V;i++){
            if(visited[i]!=true){
                 topoSort(s1,i,adj,visited);
            }
        }
     
        vector<int>s[V];
        for(int i=0;i<V;i++){
            vector<int>m;
            s[i]=m;
        }
        
        transpose_graph(adj,s,V);
        
         bool * visited1=new bool[V];
        for(int i=0;i<V;i++){
            visited1[i]=false;
        }
        int count=0;
        while(s1.size()!=0){
            int topVertex=s1.top();
            if(visited1[topVertex]!=true){
                count++;
                dfs_traversal(s,visited1,topVertex);
            }
            s1.pop();
        }
        return count;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends