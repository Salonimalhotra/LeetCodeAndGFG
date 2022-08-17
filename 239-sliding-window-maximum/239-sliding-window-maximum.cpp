#include<vector>
#include<queue>
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//          vector<int> ans;
        
//         if(k>nums.size()){
//             ans.push_back(*max_element(nums.begin(),nums.end()));
//             return ans;
//         }
        
//         int i=0,j=0;
        
//         deque<int> q;
//          // q.push(nums[j++]);
//         while(j<nums.size()){
//             // if(q.empty()){
//             //     q.push(nums[j]);
//             //     j++;
//             //     continue;
//             // }
             
//             while(!(q.empty()) && nums[j]>q.back()){
//                 q.pop_back();
//             }
//              q.push_back(nums[j]);
//             if(j-i+1==k){
//                 ans.push_back(q.front());
//                 if(nums[i]==q.front()){
//                     q.pop_front();
//                 }
//                 i++;
//             }
            
            
            
           
//             j++;
//         }
//         return ans;
         vector<int>ans;
        // for(int i=0;i<=n-k;i++){
        //     int maxAns=INT_MIN;
        //     for(int j=i;j<i+k;j++){
        //         maxAns=max(arr[j],maxAns);
        //     }
        //     ans.push_back(maxAns);
        // }
        // return ans;
        
         deque<pair<int,int>>q;
        int i=0;
        int j=0;
        while(j<nums.size()){
           if(q.size()==0){
               q.push_front(make_pair(nums[j],j));
           }
           else if(q.front().first<nums[j]){
               while(q.size()!=0 && q.front().first<nums[j]){
                   q.pop_front();
               }
               q.push_front(make_pair(nums[j],j));
           }
           else if(q.front().first>=nums[j]){
               while(q.size()!=0 && q.back().first<nums[j]){
                   q.pop_back();
               }
               q.push_back(make_pair(nums[j],j));
           }
           
           if(j-i+1<k){
               j++;
           }
           
           else if(j-i+1==k){
               ans.push_back(q.front().first);
                if(q.front().second<=i){
                    q.pop_front();
                }
               i++;
               j++;
           }
        }
        return ans;
    }
};