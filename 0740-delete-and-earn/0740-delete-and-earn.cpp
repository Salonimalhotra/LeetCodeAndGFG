class Solution
{
    public:
        int helper(vector<pair<int, int>> ans, int index,vector<int>&dp)
        {
            if (index == ans.size() - 1)
            {
                return ans[index].first *ans[index].second;
            }
          
            if (index == ans.size())
            {
                return 0;
            }            

           if(dp[index]!=-1){
             return dp[index];
           }
            if(ans[index+1].first==ans[index].first+1){
               int option1 = ans[index].first *ans[index].second + helper(ans, index + 2,dp);
               int option2 = helper(ans, index + 1,dp);
                return dp[index]=max(option1, option2);    
            }
           
           else{
              return dp[index]=ans[index].first *ans[index].second + helper(ans, index + 1,dp);
           }
          
        }
    int deleteAndEarn(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> ans;
        for (auto i: mp)
        {
            pair<int, int> p1;
            p1.first = i.first;
            p1.second = i.second;
            ans.push_back(p1);
        }
        vector<int>dp(ans.size(),-1);
       return helper(ans,0,dp);
      
    }
};