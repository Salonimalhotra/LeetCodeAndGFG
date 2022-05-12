#include<vector>
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int mid=(start+end)/2;
        while(start<end){
            if(nums[mid]<nums[mid+1]){
                start=mid+1;
            }
            else{
                end=mid;
            }
            mid=(start+end)/2;
        }
        return start;
    }
};