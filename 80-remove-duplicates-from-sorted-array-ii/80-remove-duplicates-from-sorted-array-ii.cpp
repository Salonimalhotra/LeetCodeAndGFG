class Solution {
public:
    int helper(vector<int>&nums,int index){
        if(index==nums.size()){
           return 0;
        }
        if(index==nums.size()-1){
            return 1;
        }
        
        int result;
        int smallAns=helper(nums,index+1);
        if(nums[index]!=nums[index+1]){
            result=smallAns+1;
        }
        else if(nums[index]==nums[index+1]){
            if(index+2<nums.size()){
                if(nums[index]!=nums[index+2]){
                    result=smallAns+1;
                }
                else{
                    int element=nums[index];
                    for(int i=index;i<nums.size()-1;i++){
                        nums[i]=nums[i+1];
                    }
                    nums.pop_back();
                    result=smallAns;
                }
            }
            else{
                 result=smallAns+1;
            }
        }
        return result;
        
    }
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int size=helper(nums,0);
        return size;
    }
};