#include<bits/stdc++.h>
class Solution {
public:
    int firstOcc(vector<int>&nums, int target){
        int start=0;
        int end=nums.size()-1;
        int first=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                first=mid;
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return first;
    }
    int lastOcc(vector<int>& nums, int target){
        int start=0;
        int end=nums.size()-1;
        int last=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                last=mid;
                start=mid+1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return last;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int first=firstOcc(nums,target);
        int last=lastOcc(nums,target);
        if(first==last && first==-1){
            return ans;
        }
        else{
            for(int i=first;i<=last;i++){
                ans.push_back(i);
            }
            return ans;
        }
        
        
    }
};