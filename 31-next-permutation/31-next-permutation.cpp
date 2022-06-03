#include<vector>
#include<algorithm>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       // using stl
        next_permutation(nums.begin(),nums.end());
        return;
    }
};