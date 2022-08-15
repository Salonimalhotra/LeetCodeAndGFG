class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>>mp;
        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>>ans;
        for(auto i:mp){
            int cnt=0;
            int k=i.first;
            while(cnt!=i.second.size()){
                int m=0;
                vector<int>ans1;
                while(m!=k){
                    ans1.push_back(i.second[cnt]);
                    cnt++;
                    m++;
                }
                ans.push_back(ans1);
            }
        }
        return ans;
    }
};