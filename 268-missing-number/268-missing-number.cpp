#include<unordered_map>
#include<vector>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,bool>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]=true;
        }
        int ans=-1;
        for(int i=0;i<=nums.size();i++){
            if(map.find(i)==map.end()){
                ans=i;
                break;
            }
        }
        return ans;
    }
};