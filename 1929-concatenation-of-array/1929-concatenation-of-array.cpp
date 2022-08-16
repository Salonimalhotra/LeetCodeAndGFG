class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // vector<int>ans;
//         for(int i=0;i<nums.size();i++){
//             ans.push_back(nums[i]);
//         }
        
//          for(int i=0;i<nums.size();i++){
//             ans.push_back(nums[i]);
//         }
        
//         return ans;
        int size=nums.size();
        for(int i=0;i<size;i++){
            nums.push_back(nums[i]);
        }
        return nums;
        
    }
};