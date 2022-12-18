class Solution
{
    public:
        int countConsistentStrings(string allowed, vector<string> &words)
        {
            unordered_map<char, int> mp;
            for (int i = 0; i < allowed.size(); i++)
            {
                mp[allowed[i]]++;
            }
            int cnt = 0;
            for (int j = 0; j < words.size(); j++)
            {
                bool check = true;
                for (int k = 0; k < words[j].size(); k++)
                {
                    if (mp.find(words[j][k]) == mp.end())
                {
                    check = false;
                    break;
                }
            }
            if (check == true) cnt++;
        }
    return cnt;
}
};