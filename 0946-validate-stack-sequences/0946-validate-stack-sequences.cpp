class Solution
{
    public:
        bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
        {
            stack<int> st;
            int i = 0;
            int j = 0;
            while (i < pushed.size() || j < popped.size())
            {
                if (st.size() == 0)
                {
                    if (i == pushed.size() && j != popped.size())
                    {

                        return false;
                    }
                    else
                    {
                        st.push(pushed[i]);
                        i++;
                    }
                }
                else
                {
                    if (st.top() == popped[j])
                    {
                        st.pop();
                        j++;
                    }
                    else
                    {
                        if (i != pushed.size())
                        {
                            st.push(pushed[i]);
                            i++;
                        }
                        else {
                          return false;
                        }
                    }
                }
            }
            if (i == pushed.size() && j == popped.size()) return true;
            else return false;
        }
};