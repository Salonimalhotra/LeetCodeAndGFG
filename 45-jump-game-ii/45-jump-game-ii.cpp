#include<vector>
class Solution {
public:
    int jump(vector<int>& arr) {
        int n=arr.size();
        if(arr.size()<=1){
            return 0;
        }
        int maxreach=arr[0];
        int steps=arr[0];
        int jumps=1;
        for(int i=1;i<n;i++){
            if(i==n-1){
                return jumps;
            }
            steps--;
            maxreach=max(maxreach,arr[i]+i);
            
            if(steps==0){
                jumps++;
                if(i>=maxreach){
                    return -1;
                }
                steps=maxreach-i;
            }
        }
        
        return jumps;
    }   
};