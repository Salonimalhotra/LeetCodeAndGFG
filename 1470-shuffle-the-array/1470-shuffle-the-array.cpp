#include<vector>
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>finalAns;
        int i=0;
        int j=n;
        while(i<n && j<2*n){
            finalAns.push_back(nums[i]);
            finalAns.push_back(nums[j]);
            i++;
            j++;
        }
        
        return finalAns;
        
    }
};