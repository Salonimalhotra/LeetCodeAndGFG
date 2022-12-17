class Solution
{
    public:

        int evalRPN(vector<string> &tokens)
        {
            if (tokens.size() == 1) return stoi(tokens[0]);
            stack<long long > st;
            for (int i = 0; i < tokens.size(); i++)
            {
                if (tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/")
                {
                    long long top1 = st.top();
                    st.pop();
                    long long  top2 = st.top();
                    st.pop();
                    long long  ans;
                    if (tokens[i] == "*") ans=(top1 *top2);
                    else if (tokens[i] == "+") ans=(top1 + top2);
                    else if (tokens[i] == "-") ans=(top2 - top1);
                    else if (tokens[i] == "/") ans=(top2 / top1);
                   st.push(ans);
                }
                else
                {
                    int element = stoi(tokens[i]);
                    st.push(element);
                }
            }
            return st.top();
        }
};