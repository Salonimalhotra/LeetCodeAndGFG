#include<vector>
#include<algorithm>
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++){
            pair<int,int>p;
            p.first=nums[i];
            p.second=i;
            ans.push_back(p);
        }
        sort(ans.begin(),ans.end());
        pair<int,int>maX=ans[ans.size()-1];
        for(int i=ans.size()-2;i>=0;i--){
            if(maX.first<2*ans[i].first){
                return -1;
            }
        }
        return maX.second;
    }
};