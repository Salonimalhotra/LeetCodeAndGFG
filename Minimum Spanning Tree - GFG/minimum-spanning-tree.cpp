// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
         vector<pair<int,int>>newadj[V];
         for(int i=0;i<V;i++){
                vector<pair<int,int>>t1;
             for(int j=0;j<adj[i].size();j++){
                 int adjVertex=adj[i][j][0];
                 int adjWeight=adj[i][j][1];
                 pair<int,int>p1;
                 p1.first=adjVertex;
                 p1.second=adjWeight;
                 t1.push_back(p1);
             }
             newadj[i]=t1;
         }
         
         int *weights=new int[V];
         for(int i=0;i<V;i++){
             weights[i]=INT_MAX;
         }
         weights[0]=0;
         
         int * parents=new int[V];
         for(int i=0;i<V;i++){
             parents[i]=-1;
         }
         
         bool * visited=new bool[V];
         for(int i=0;i<V;i++){
             visited[i]=false;
         }
         
         for(int i=0;i<V;i++){
             int minWeight=INT_MAX;
             int min_Vertex=-1;
             for(int i=0;i<V;i++){
                 if(visited[i]!=true && weights[i]<minWeight){
                     minWeight=weights[i];
                     min_Vertex=i;
                 }
             }
             visited[min_Vertex]=true;
             for(int i=0;i<newadj[min_Vertex].size();i++){
                 if(visited[newadj[min_Vertex][i].first]!=true && weights[newadj[min_Vertex][i].first]>newadj[min_Vertex][i].second){
                     weights[newadj[min_Vertex][i].first]=newadj[min_Vertex][i].second;
                     parents[newadj[min_Vertex][i].first]=min_Vertex;
                 }
             }
         }
         int finalAns=0;
         for(int i=0;i<V;i++){
             finalAns+=weights[i];
         }
         return finalAns;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends