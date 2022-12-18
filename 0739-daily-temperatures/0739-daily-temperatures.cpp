class Solution
{
    public:
        vector<int> dailyTemperatures(vector<int> &temperatures)
        {
            int n = temperatures.size();
            stack<pair<int, int>> st;
            st.push({ temperatures[n - 1],
                n - 1 });
            vector<int> ans(n, 0);
            for (int i = n - 2; i >= 0; i--)
            {
                while (st.size() != 0 && st.top().first <= temperatures[i])
                {
                    st.pop();
                }
                if (st.size() != 0)
                {
                    ans[i]=st.top().second - i;
                }
                st.push(make_pair(temperatures[i], i));
            }
            return ans;
        }
};