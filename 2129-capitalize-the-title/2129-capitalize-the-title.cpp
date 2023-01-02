class Solution
{
    public:
        string capitalizeTitle(string title)
        {
            int j = 0;
            string finalans = "";
            while (j < title.size())
            {
                string st = "";
                while (j < title.size() && title[j] != ' ')
                {
                    st.push_back(title[j]);
                    j++;
                }
                string finalst = "";
                if (st.size() == 1 || st.size() == 2)
                {
                    transform(st.begin(), st.end(), st.begin(), ::tolower);
                    finalst = st;
                }
                else
                {
                    string st1 = st.substr(1);
                   transform(st1.begin(), st1.end(), st1.begin(), ::tolower);
                    
                    if (st[0] >= 'a' && st[0] <= 'z')
                    {
                        st[0] = st[0] - 32;
                    }
                    finalst.push_back(st[0]);
                    finalst.append(st1);
                }
                finalans.append(finalst);
                if (j == title.size())
                {
                    break;
                }
                else
                {
                    finalans.push_back(' ');
                    j++;
                }
            }
            return finalans;
        }
};