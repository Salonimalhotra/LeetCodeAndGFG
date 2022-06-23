#include<vector>
#include<algorithm>
class Solution {
public:
    pair<int,int> maxElementIndex(vector<int>&nums){
        int maxElement=INT_MIN;
        int maxIndex=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxElement){
                maxElement=nums[i];
                maxIndex=i;
            }
        }
        pair<int,int>p;
        p.first=maxElement;
        p.second=maxIndex;
        return p;
    }
    int dominantIndex(vector<int>& nums) {
        pair<int,int>maX=maxElementIndex(nums);        
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]!=maX.first && maX.first<2*nums[i]){
                return -1;
            }
        }
        return maX.second;
    }
};