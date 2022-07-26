class Solution {
public:
    bool helper(int i,int * color,vector<vector<int>>& graph){
        queue<int>q;
        q.push(i);
        color[i]=1;
        while(q.size()!=0){
            int top=q.front();
            q.pop();
            for(auto i:graph[top]){
                if(color[i]==-1){
                    color[i]=1-color[top];
                    q.push(i);
                }
                else{
                    if(color[i]==color[top]){
                        return false;
                    }
                    else{
                        continue;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int * color=new int[n];
        
        for(int i=0;i<n;i++){
            color[i]=-1;
        }
        
        for(int i=0;i<n;i++){
           if(color[i]==-1){
              bool smallAns=helper(i,color,graph);
               if(!smallAns){
                   return false;
               }
           }
        }
        return true;
    }
};