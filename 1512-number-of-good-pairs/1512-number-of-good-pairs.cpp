#include<unordered_map>
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       unordered_map<int,int>map;
        int count=0;
        for(int i=0;i<nums.size();i++){          
            if(map.find(nums[i])!=map.end()){
                count+=map[nums[i]];
            }
            map[nums[i]]++;
        }
        return count;
    }
};