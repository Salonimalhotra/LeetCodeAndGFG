#include<vector>
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>prefixSum(nums.size(),0);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
            prefixSum[i]=ans;
        }
        ans=0;
        vector<int>suffixSum(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            ans+=nums[i];
            suffixSum[i]=ans;
        }
        int pivot_index=-1;
        
        for(int i=0;i<nums.size();i++){
            int leftSum=0;
            if(i-1>=0){
                leftSum=prefixSum[i-1];
            }
            int rightSum=0;
            if(i+1<nums.size()){
                rightSum=suffixSum[i+1];
            }
            if(leftSum==rightSum){
                pivot_index=i;
                break;
            }
        }
        return pivot_index;
    }
};