#include<vector>
#include<algorithm>
class Solution {
public:
    void reverse(vector<int>&nums,int s,int e){
        while(s<e){
            swap(nums[s],nums[e]);
               s++;
               e--;          
        }
        return;
    }
    void nextPermutation(vector<int>& nums) {
       // using stl
        // next_permutation(nums.begin(),nums.end());
        // return;
        bool flag=false;
        int indx1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                flag=true;
                indx1=i-1;
                break;
            }
        }
        
        if(flag==false){
            reverse(nums,0,nums.size()-1);
        }
        
        else{
            // int indx1=i-1;
            int indx2;
            for(int j=nums.size()-1;j>indx1;j--){
                if(nums[j]>nums[indx1]){
                    indx2=j;
                    break;
                }
            }
            swap(nums[indx1],nums[indx2]);
            reverse(nums,indx1+1,nums.size()-1);
        }
        return;
    }
    
};