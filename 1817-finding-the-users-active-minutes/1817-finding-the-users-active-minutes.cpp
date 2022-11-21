class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int>ans(k,0);
        map<int,set<int>>mp;
        for(int i=0;i<logs.size();i++){
          int uid=logs[i][0];
          int min=logs[i][1];
          mp[uid].insert(min);
        }
        for(auto i:mp){
          int cnt=0;
          for(auto j:i.second){
           cnt++;
          }
          ans[cnt-1]++;
        }
        return ans;
    }
};