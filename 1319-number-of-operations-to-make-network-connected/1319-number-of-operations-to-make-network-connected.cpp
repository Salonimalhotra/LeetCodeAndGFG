#include<vector>
class Solution {
public:
    int findParent(int u,int * parent){
        if(parent[u]==u){
            return u;
        }
        else{
            return parent[u]=findParent(parent[u],parent);
        }
    }    
    void unionn(int a,int b,int * ranks,int * parent,int &ans){        
        int parent_a=findParent(a,parent);
        int parent_b=findParent(b,parent);
        
        if(parent_a==parent_b && a!=b){
            //cycle is detected
            ans++;   
            return;
        }
        else if(ranks[parent_a]>ranks[parent_b]){
            parent[parent_b]=parent_a;
        }
        else if(ranks[parent_b]>ranks[parent_a]){
            parent[parent_a]=parent_b;
        }
        else{
             parent[parent_b]=parent_a;
             ranks[parent_a]++;
        }
        return;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(n-1>connections.size()){
            return -1;
        }
        int ans=0;
        int * parent=new int[n];
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int * ranks=new int[n];
        for(int i=0;i<n;i++){
            ranks[i]=0;
        }
        for(int i=0;i<connections.size();i++){
            unionn(connections[i][0],connections[i][1],ranks,parent,ans);
        }
        int unconnected=0;
        
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                unconnected++;
            }
        }
        
        if(unconnected-1>ans){
            return -1;
        }
        // if extra edges are greater than unconnected,then it means that we have edges to connect unconnectd components  
        return unconnected-1;
    }
};