#include<bits/stdc++.h>
class Solution {
public:
    int nextgap(int gap){
        if(gap<=1){
            return 0;
        }
        return (int)ceil(gap / 2.0);
    }
    void swap(vector<int>&nums,int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
        return;
    }
    void merge(vector<int>&nums,int s,int mid,int e){
//         int len=e-s+1;
//         vector<int>arr(len,0);
//         int i=s;
//         int j=mid+1;
//         int k=0;
//         while(i<=mid && j<=e){
//             if(nums[i]<=nums[j]){
//                 arr[k]=nums[i];
//                 k++;
//                 i++;
//             }
//             else{
//                 arr[k++]=nums[j++];
//             }
//         }
        
//         while(i<=mid){
//              arr[k]=nums[i];
//                 k++;
//                 i++;
//         }
        
//         while(j<=e){
//              arr[k++]=nums[j++];
//         }
//         k=0;
//         for(int i=s;i<=e;i++){
//             nums[i]=arr[k++];
//         }
//         return;
        
        int gap=e-s+1;
        for(gap=nextgap(gap);gap>0;gap=nextgap(gap)){
           int i=s;
           int j=s+gap;
           while(i<=e && j<=e){
               if(nums[i]>nums[j]){
                 swap(nums,i,j);
               }
               i++;
               j++;
           }
        }
        return;
    }
    void mergeSort(vector<int>&nums,int s,int e){
        if(s>=e){
            return;
        }
        int mid=(s+e)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,mid,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};