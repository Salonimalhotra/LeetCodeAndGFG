class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
             pair<int,int>p1;
            p1.first=nums[i];
            p1.second=i;
            v.push_back(p1);
        }
        
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(i==0){
                nums[v[i].second]=i;
            }
            else if(v[i].first==v[i-1].first){
                 nums[v[i].second]=nums[v[i-1].second];
            }
            else{
              nums[v[i].second]=i;   
            }
        }
        return nums;
    }
};