#include<unordered_map>
#include<vector>
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0){
            return 0;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
           mp[nums[i]]++;
        }
        int count=0;
        for(auto i:mp){
            if(mp.find(i.first+k)!=mp.end() && k>0){
                count++;
            }
            else if(k==0){
                if(i.second>1){
                    count++;
                }
            }
        }
        return count;
    }
};