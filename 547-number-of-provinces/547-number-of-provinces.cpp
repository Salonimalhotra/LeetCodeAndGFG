class Solution {
public:
    void dfs(int vertex,bool * visited,vector<vector<int>>& isConnected){
        visited[vertex]=true;
        for(int i=0;i<isConnected.size();i++){
            if(visited[i]!=true && isConnected[vertex][i]==1){
                dfs(i,visited,isConnected);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n=isConnected.size();
        bool * visited=new bool[n];
        
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]!=true){
                count++;
                dfs(i,visited,isConnected);
            }
        }
        return count;
    }
};