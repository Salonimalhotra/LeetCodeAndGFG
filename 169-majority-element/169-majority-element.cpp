#include<map>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>ourMap;
        for(int i=0;i<nums.size();i++){
            ourMap[nums[i]]++;
        }
        int max_count=0;
        int max_element=nums[0];
        for(auto i:ourMap){
            if(i.second>max_count){
                max_count=i.second;
                max_element=i.first;
            }
        }
        
        return max_element;
    }
};