#include<vector>
#include<climits>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1){
           return nums.size();
        }
        int max_len=1;
        sort(nums.begin(),nums.end());
        int len=1;
        bool check=true;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                len++;
                max_len=max(max_len,len);
            }
            else if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                len=1;
                max_len=max(max_len,len);
            }
        }
        
        return max_len;
    }
};