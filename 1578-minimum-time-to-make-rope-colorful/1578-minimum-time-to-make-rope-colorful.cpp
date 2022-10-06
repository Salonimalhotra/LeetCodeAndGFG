class Solution
{
    public:
        int minCost(string colors, vector<int> &neededTime)
        {
            if (colors.size() == 0 || colors.size() == 1) return 0;
            stack<pair<char, int>> st;
            int ans = 0;
            for (int i = 0; i < colors.size(); i++)
            {
                if (st.size() != 0 && st.top().first == colors[i])
                {
                    if (st.top().second <= neededTime[i])
                    {
                        ans += st.top().second;
                        st.pop();
                        st.push(make_pair(colors[i], neededTime[i]));
                    }
                    else
                    {
                        ans += neededTime[i];
                    }
                }
                else {
                     st.push(make_pair(colors[i], neededTime[i]));
                }
              
            }
          return ans;
        }
};