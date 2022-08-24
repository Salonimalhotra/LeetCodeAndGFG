class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>>pq;
        for(auto i:mp){
            pq.push(make_pair(i.second,i.first));
        }
        int temp=0;
        vector<int>finalAns;
        while(pq.size()!=0 && temp!=k){
            finalAns.push_back(pq.top().second);
            pq.pop();
            temp++;
        }
        
        return finalAns;
        
    }
};