class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        //space complexity-O(N)
        //time complexity-O(N)
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        //time compexity-O(N)
        vector<pair<int,int>>v;
        for(auto i:mp){
            v.push_back(make_pair(i.second,i.first));
        }
        //time complexity-O(NlogN)
        sort(v.begin(),v.end(),greater());
        
        //time complexity()
        vector<int>m;
        for(int i=0;i<k;i++){
            m.push_back(v[i].second);
        }
        
        return m;
        
    }
};