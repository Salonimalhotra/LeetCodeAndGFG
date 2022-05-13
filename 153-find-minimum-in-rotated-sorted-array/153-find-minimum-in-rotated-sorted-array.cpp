#include<vector>
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0]<nums[nums.size()-1]){
            return nums[0];
        }
        int start=0;
        int end=nums.size()-1;
        int mid=(start+end)/2;
        while(start<end){
            if(nums[mid]>=nums[0]){
                start=mid+1;
            }
            else{
                end=mid;
            }
            mid=(start+end)/2;
        }
        return nums[start];
        
    }
};