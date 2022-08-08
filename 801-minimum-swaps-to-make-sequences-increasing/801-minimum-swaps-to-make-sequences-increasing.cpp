class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // bottom up DP
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int n=nums1.size();
        vector<int>last(2,0);
        vector<int>curr(2,0);
        for(int index=n-1;index>=1;index--){
            for(int swapped=1;swapped>=0;swapped--){
                int prev1=nums1[index-1];
                int prev2=nums2[index-1];
                if(swapped){
                    swap(prev1,prev2);
                }
                int ans=INT_MAX;
                if(nums1[index]>prev1 && nums2[index]>prev2){
                    ans=min(ans,last[0]);
                }
                if(nums1[index]>prev2 && nums2[index]>prev1){
                    ans=min(ans,1+last[1]);
                }
                curr[swapped]=ans;
            }
            last=curr;
        }
        return last[0];
    }
};