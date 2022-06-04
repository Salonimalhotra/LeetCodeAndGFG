#include<vector>
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
//         3 1 -2 -5 2 4 
//         mid element=nums.size()==6/2
//             3
//         int i=0;
//         int j=midelement;
//         if(3>+ve)
      vector<int>nums1;
      vector<int>nums2;  
     for(int i=0;i<nums.size();i++){
         if(nums[i]<0){
             nums2.push_back(nums[i]);
         }
         else{
             nums1.push_back(nums[i]);
         }
     }
     
    int i=0;
    int j=0;
    int k=0;
    while(k<nums.size()){
        if(k%2==0){
            nums[k]=nums1[i];
            i++;
            k++;
        }
        else{
            nums[k]=nums2[j];
            j++;
            k++;
        }
    }
        return nums;
        
    }
};