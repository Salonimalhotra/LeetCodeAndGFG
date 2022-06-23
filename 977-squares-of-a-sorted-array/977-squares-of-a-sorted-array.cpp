#include<vector>
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // for(int i=0;i<nums.size();i++){
        //     nums[i]=nums[i]*nums[i];
        // }
        // sort(nums.begin(),nums.end());
        // return nums;
        int i=0;
        vector<int>finalAns(nums.size(),0);
        int j=nums.size()-1;
        int k=nums.size()-1;
        while(i<=j){
            if(abs(nums[i])>=abs(nums[j])){
                finalAns[k--]=nums[i]*nums[i];
                i++;
            }
            else{
                finalAns[k--]=nums[j]*nums[j];
                j--;
            }
        }
        return finalAns;
    }
};