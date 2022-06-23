#include<vector>
class Solution {
public:
    void reverse(vector<int>&nums,int s,int e){
        int i=s;
        int j=e;
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        return;
    }
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        bool flag=true;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                idx=i-1;
                flag=false;
                break;
            }
        }
        if(flag){
            return reverse(nums,0,nums.size()-1);
        }
        int x;
        for(int i=nums.size()-1;i>idx;i--){
            if(nums[i]>nums[idx]){
                x=i;
                break;
            }
        }
        swap(nums[idx],nums[x]);
        reverse(nums,idx+1,nums.size()-1);
        return;
        
    }
};