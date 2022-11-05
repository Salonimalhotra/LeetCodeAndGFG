#include <vector>

class Solution
{
    public:
        int helper(vector<int> &nums, int start, int end, int mid)
        {
            if (start > end)
            {
                return -1;
            }

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
          
            if(nums[mid]<nums[mid+1]){
              return helper(nums,mid+1,end,(start+end)/2);
            }
          else if(nums[mid]<nums[mid-1]){
              return helper(nums,start,mid-1,(start+end)/2);
          }
          
          return -1;
        }
    int findPeakElement(vector<int> &nums)
    {
       	// int start=1;
       	// int end=nums.size()-2;

       	//         if(nums[0]>nums[1]){
       	//             return 0;
       	//         }
       	//         else if(nums[nums.size()-1]>nums[nums.size()-2]){
       	//            return nums.size()-1;
       	//         }

       	//         int start=1;
       	//         int end=nums.size()-2;
       	//         while(start<=end){
       	//           int mid=start+(end-start)/2;
       	//           if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
       	//               return mid;
       	//           }
       	//           else if(nums[mid] < nums[mid-1]){
       	//                 end=mid-1;
       	//            }
       	//          else if(nums[mid]<nums[mid+1]){
       	//                start=mid+1;
       	//            }
       	//         }
       	//         return -1;
        if(nums.size()==1){
          return 0;
        }
        if (nums[0] > nums[1])
        {
            return 0;
        }
        else if (nums[nums.size() - 1] > nums[nums.size() - 2])
        {
            return nums.size() - 1;
        }
        int start = 1;
        int end = nums.size() - 2;
        int mid = (start + (end - start) / 2);
        return helper(nums,start,end,mid);
        
    }
};