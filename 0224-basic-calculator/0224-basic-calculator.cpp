class Solution
{
    public:
        int calculate(string s)
        {
            stack<int> st;
       
            int sign = 1;
            int ans = 0;
            for (int i = 0; i < s.size(); i++)
            {

                if (s[i] >= '0' && s[i] <= '9')
                {
                    int result = s[i] - '0';
                    while (i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '9')
                    {
                        result = result *10 + (s[i + 1] - '0');
                        i++;
                    }

                    ans += result * sign;
                }
                else if (s[i] == '-')
                {
                    sign = -1;
                }
                else if (s[i] == '+')
                {
                    sign = 1;
                }
                else if (s[i] == '(')
                {
                    st.push(ans);
                    st.push(sign);
                    ans = 0;
                    sign = 1;
                }
                else if (s[i] == ')')
                {
                   
                    ans = ans * st.top();
                    st.pop();
                    ans += st.top();
                    st.pop();
                }
            }
          return ans;
        }
};