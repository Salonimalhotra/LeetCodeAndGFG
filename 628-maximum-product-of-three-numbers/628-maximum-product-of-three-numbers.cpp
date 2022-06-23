#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxAns=INT_MIN;
        sort(nums.begin(),nums.end());
        int prod=1;
        int m=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(m==3){
                break;
            }
            else{
                prod*=nums[i];
                m++;
            }
        }
        
        maxAns=max(maxAns,prod);
        prod=1;
        for(int i=0;i<3;i++){
            prod*=nums[i];
        }
        maxAns=max(maxAns,prod);
        
        prod=1;
        prod=nums[nums.size()-1]*nums[0]*nums[1];
        maxAns=max(maxAns,prod);
        return maxAns;
       
        
    }
};