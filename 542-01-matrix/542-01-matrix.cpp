#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    //Brute Force:-
    // int dis(int row,int col,int m,int n,vector<vector<int>>&mat){
    //     vector<vector<bool>>visited(m,vector<bool>(n,false));
    //     pair<int,pair<int,int>>p1;
    //     queue<pair<int,pair<int,int>>>q;
    //     q.push(make_pair(0,make_pair(row,col)));
    //     visited[row][col]=true;
    //     while(q.size()!=0){
    //         pair<int,pair<int,int>> top=q.front();
    //         q.pop();
    //         int dis=top.first;
    //         int row=top.second.first;
    //         int col=top.second.second;
    //         if(row+1<m && col<n && row+1>=0 && col>=0 && visited[row+1][col]!=true){
    //             if(mat[row+1][col]==0){
    //                 return dis+1;
    //             }
    //             visited[row+1][col]=true;
    //             q.push(make_pair(dis+1,make_pair(row+1,col)));
    //         }
    //         if(row-1<m && col<n && row-1>=0 && col>=0 &&  visited[row-1][col]!=true){
    //             if(mat[row-1][col]==0){
    //                 return dis+1;
    //             }
    //             visited[row-1][col]=true;
    //             q.push(make_pair(dis+1,make_pair(row-1,col)));                
    //         }
    //          if(row<m && col+1<n && row>=0 && col+1>=0 && visited[row][col+1]!=true){
    //             if(mat[row][col+1]==0){
    //                 return dis+1;
    //             }
    //             visited[row][col+1]=true;
    //             q.push(make_pair(dis+1,make_pair(row,col+1)));
    //         }
    //         if(row<m && col-1<n && row>=0 && col-1>=0 &&  visited[row][col-1]!=true){
    //             if(mat[row][col-1]==0){
    //                 return dis+1;
    //             }
    //             visited[row][col-1]=true;
    //             q.push(make_pair(dis+1,make_pair(row,col-1)));                
    //         }            
    //     }
    //     return -1;
    // }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
//       Brute force;
//         vector<vector<int>>ans(m,vector<int>(n,0));
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                if(mat[i][j]==0){
//                    continue;
//                }
//                 else{
//                     ans[i][j]=dis(i,j,m,n,mat);
//                 }
                
//             }
//         }
//         return ans;
        
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<pair<int,pair<int,int>>>q;
      
        
        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push(make_pair(0,make_pair(i,j)));
                }
               else{
                   continue;
               }
           }
        }
        
        int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
        
        
        while(q.size()!=0){
            pair<int,pair<int,int>>top=q.front();
            int lvl=top.first;
            int row=top.second.first;
            int col=top.second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int rowi=row+dir[i][0];
                int coli=col+dir[i][1];
                
                if(rowi>=0 && rowi<m && coli>=0 && coli<n && ans[rowi][coli]==-1){
                   q.push(make_pair(lvl+1,make_pair(rowi,coli)));
                    ans[rowi][coli]=lvl+1;                    
                }               

           }
         
        }
        return ans;
    }
};