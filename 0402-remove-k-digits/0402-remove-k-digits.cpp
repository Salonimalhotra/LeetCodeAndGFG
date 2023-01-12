class Solution
{
    public:
        string removeKdigits(string num, int k)
        {
            int x = k;
            if (k >= num.size()) return "0";
            stack<char> st;
            for (int i = 0; i < num.size(); i++)
            {
                while (st.size() != 0 && st.top() > num[i] && k != 0)
                {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }

            while (k != 0 && st.size() != 0)
            {
                st.pop();
                k--;
            }

            char *ans = new char[num.size() - x];
            int n = num.size() - x;
            while (st.size() != 0)
            {
                ans[n - 1] = st.top();
                st.pop();
                n--;
            }
            string finalans = "";
            bool check = false;
            for (int i = 0; i < num.size() - x; i++)
            {
                if (ans[i] == '0')
                {
                    if (check == false) continue;
                    else finalans.push_back(ans[i]);
                }
                else
                {
                    check = true;
                    finalans.push_back(ans[i]);
                }
            }

            if (finalans.size() == 0)
            {
                return "0";
            }
            return finalans;
        }
};