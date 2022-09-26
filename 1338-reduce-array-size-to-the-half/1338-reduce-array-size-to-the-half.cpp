class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
        }
        
        priority_queue<pair<int,int>>pq;
        for(auto j:mp){
            pq.push(make_pair(j.second,j.first));
        }
        
        int minAns=0;
        int sum=0;
        while(sum<arr.size()/2){
            sum+=pq.top().first;
            minAns++;
            pq.pop();
        }
        return minAns;
    }
};