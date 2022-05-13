class Solution {
public:
    int binarySearch(vector<int>&nums,int target){
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else {
                end=mid-1;
            }
            
        }
        return -1;
    }
    int findPos(vector<int>&nums,int target){
        int start=0;
        int end=nums.size()-1;
        
          while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else {
                end=mid-1;
            }
            
        }
        return start;        
    }
    int searchInsert(vector<int>& nums, int target) {
        int ans=binarySearch(nums,target);
        if(ans!=-1){
            return ans;
        }
        else{
            ans=findPos(nums,target);
        }
        return ans;
    }
};