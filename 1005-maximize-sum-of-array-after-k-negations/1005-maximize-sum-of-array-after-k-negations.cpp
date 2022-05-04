#include<vector>
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=0;
        int i=0;
        while(i<nums.size() && count!=k){
            if(nums[i]<0){
                nums[i]=-1*nums[i];
                count++;
            }
            i++;
        }
        sort(nums.begin(),nums.end());
        int left_over=k-count;
        int ans=0;
        if(count==k || left_over%2==0){
            int sum=0;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
            }
            ans=sum;
        }
        else if(left_over%2!=0){
           for(int i=0;i<nums[i];i++){
               if(nums[i]>0){
                   nums[i]=-1*nums[i];
                   break;
               }
           }            
           int sum=0;
           for(int i=0;i<nums.size();i++){
                sum+=nums[i];
            }
            ans=sum;
      }
        return ans;
        
    }
};