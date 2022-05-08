// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
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
         
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         vector<int>dis(V,INT_MAX);
         dis[S]=0;
         pq.push(make_pair(0,S));
         bool * visited=new bool[V];
         for(int i=0;i<V;i++){
             visited[i]=false;
         }
         
         while(pq.size()!=0){
             pair<int,int>topElement=pq.top();
             int distanceTopNode=topElement.first;
             int Node=topElement.second;
             pq.pop();
             visited[Node]=true;
             for(int i=0;i<newadj[Node].size();i++){
                 if(visited[newadj[Node][i].first]!=true && dis[newadj[Node][i].first]>distanceTopNode+newadj[Node][i].second){
                     dis[newadj[Node][i].first]=distanceTopNode+newadj[Node][i].second;
                     pq.push(make_pair(dis[newadj[Node][i].first],newadj[Node][i].first));
                 }
             }
         }
         
        vector<int>ans;
        for(int i=0;i<V;i++){
            ans.push_back(dis[i]);
        }
        return ans;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends