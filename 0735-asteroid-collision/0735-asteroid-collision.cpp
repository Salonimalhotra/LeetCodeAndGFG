class Solution
{
    public:
        vector<int> asteroidCollision(vector<int> &asteroids)
        {
            vector<int> ans;
            stack<int> st;
            for (int i = 0; i < asteroids.size();)
            {
                if (st.size() == 0)
                {
                    st.push(asteroids[i]);
                    i++;
                }
                else if (st.size() != 0)
                {
                    if ((asteroids[i] < 0 && st.top() > 0))
                    {
                        if (abs(asteroids[i]) > abs(st.top()))
                        {
                            st.pop();
                        }
                        else if (abs(asteroids[i]) == abs(st.top()))
                        {
                            st.pop();
                            i++;
                            continue;
                        }
                        else
                        {
                            i++;
                            continue;
                        }
                    }
                    else
                    {
                        st.push(asteroids[i]);
                        i++;
                    }
                }
            }
            while (st.size() != 0)
            {
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
};