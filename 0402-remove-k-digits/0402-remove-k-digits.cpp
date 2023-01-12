class Solution
{
    public:
        string removeKdigits(string num, int k)
        {
            int x=k;
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

            char * ans = new char[num.size() - x];
            int n = num.size() - x;
            while (st.size() != 0)
            {
                ans[n - 1] = st.top();
                st.pop();
                n--;
            }
            string finalans = "";
            for (int i = 0; i < num.size() - x; i++)
            {
                finalans.push_back(ans[i]);
            }
            if (finalans[0] != '0') return finalans;
            reverse(finalans.begin(), finalans.end());
            for (int i = finalans.size() - 1; i >= 0; i--)
            {
                if (finalans[i] == '0')
                {
                    finalans.pop_back();
                }
                else
                {
                    break;
                }
            }
            reverse(finalans.begin(), finalans.end());
            if (finalans.size() == 0)
            {
                return "0";
            }
            return finalans;
        }
};