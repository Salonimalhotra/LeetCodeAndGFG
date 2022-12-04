class Solution
{
    public:
        bool isCircularSentence(string sentence)
        {
            stack<char> st;

            for (int i = 0; i < sentence.size(); i++)
            {
                if (i - 1 >= 0 && sentence[i - 1] == ' ')
                {
                    if (st.top() != sentence[i])
                    {
                        return false;
                    }
                    else
                    {
                        st.pop();
                    }
                }
                if (sentence[i + 1] == ' ' || i + 1 == sentence.size())
                {

                    st.push(sentence[i]);
                }
            }
            if (st.top() != sentence[0]) return false;
            return true;
        }
};