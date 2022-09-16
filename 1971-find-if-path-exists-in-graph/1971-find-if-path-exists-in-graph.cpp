class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
              adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        q.push(source);
        vector<bool>visited(n,false);
        visited[source]=true;
        while(q.size()!=0){
            int top=q.front();
            q.pop();
            if(top==destination){
                return true;
            }
            for(int i=0;i<adj[top].size();i++){
                if(visited[adj[top][i]]!=true){
                    q.push(adj[top][i]);
                    visited[adj[top][i]]=true;
                }
                
            }
        }
       return false;
    }
};