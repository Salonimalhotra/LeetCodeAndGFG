class cmp{
    public:
    bool operator()(pair<int,int>p1,pair<int,int>p2){
        if(p1.first>=p2.first){
            return true;
        }  
        else{
            return false;
        }    
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
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
        // sort(v.begin(),v.end(),greater());
         priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>p;
        for(int i=0;i<k && i<v.size();i++){
           p.push(make_pair(v[i].first,v[i].second));
            
        }
        
        for(int i=k;i<v.size();i++){
            if(p.top().first<v[i].first){
                p.pop();
                p.push(make_pair(v[i].first,v[i].second));
            }
        }
        
        while(p.size()!=0){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
       
        
    }
};