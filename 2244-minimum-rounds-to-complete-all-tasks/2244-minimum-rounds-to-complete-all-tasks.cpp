class Solution
{
    public:
        int minimumRounds(vector<int> &tasks)
        {
            unordered_map<int, int> mp;
            for (int i = 0; i < tasks.size(); i++)
            {
                mp[tasks[i]]++;
            }

            int ans = 0;
            for (auto i: mp)
            {
                int x = i.second;
                if (x == 1)
                {
                    return -1;
                }
                else
                {
                  if(x%3==0){
                    ans+=x/3;
                  }
                  else{
                    ans+=x/3 + 1;
                  }
                }
            }
            return ans;
        }
};