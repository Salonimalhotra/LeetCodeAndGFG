class Solution
{
    public:
        int longestPalindrome(vector<string> &words)
        {
            unordered_map<string, int> mp;
            int len = 0;
            for (int i = 0; i < words.size(); i++)
            {
                if (words[i][0] == words[i][1])
                {
                    mp[words[i]]++;
                }
                else
                {
                    string rev_key = "";
                    rev_key.push_back(words[i][1]);
                    rev_key.push_back(words[i][0]);
                    if (mp.find(rev_key) != mp.end())
                    {
                        len += 4;
                        mp[rev_key]--;
                        if (mp[rev_key] == 0) mp.erase(rev_key);
                    }
                    else
                    {
                        mp[words[i]]++;
                    }
                }
            }

            bool check = false;
            for (auto i: mp)
            {
                if (i.first[0] == i.first[1])
                {
                    if (i.second % 2 == 0)
                    {
                        len += 2 * (i.second);
                    }
                    
                    else
                    {
                        if(check==false){
                          len=len + (2 * (i.second));
                          check=true;
                        }
                      else len += 2 *(i.second-1);
                    }
                }
            }
            return len;
        }
};