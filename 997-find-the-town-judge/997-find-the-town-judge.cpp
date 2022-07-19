#include<vector>
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int matrix[n+1][n+1];
        
        memset(matrix,0,sizeof(matrix));
        
        for(int i=0;i<trust.size();i++){
            int f=trust[i][0];
            int s=trust[i][1];
            matrix[f][s]=1;
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int rowindex=-1;
        for(int i=1;i<=n;i++){
            bool check=false;
            for(int j=1;j<=n;j++){
                if(matrix[i][j]==1){
                    check=true;
                    break;
                }
            }
            if(check==false){              
                rowindex=i;
                // cout<<rowindex<<endl;                
                break;
            }            
        }
        // if(matrix[1][2]==1){
        //     cout<<"true"<<endl;
        // }
        
        if(rowindex==-1){
            return -1;
        }
        else{
            for(int i=1;i<=n;i++){
               if(matrix[i][rowindex]==1 || i==rowindex){                   
                   continue;
               }
                else if(matrix[i][rowindex]!=1){
                    // cout<<i<<" "<<rowindex<<endl;
                    // cout<<"returning"<<endl;
                    return -1;
                }
                
            }
            return rowindex;
        }
    }
};