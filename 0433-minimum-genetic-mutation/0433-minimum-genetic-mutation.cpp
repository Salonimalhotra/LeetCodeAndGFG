class Solution
{
    public:
        int minMutation(string start, string end, vector<string> &bank)
        {
            unordered_map<string, int> mp;
            unordered_map<string, int> mp1;
            for (int i = 0; i < bank.size(); i++)
            {
                mp[bank[i]]++;
            }

            queue<pair<string, int>> q;
            mp1[start]++;
            q.push(make_pair(start, 0));
            while (q.size() != 0)
            {
                pair<string, int> topElement = q.front();
                q.pop();
                if (topElement.first == end)
                {
                    return topElement.second;
                }

                string x = topElement.first;
                for (int i = 0; i < 8; i++)
                {
                    char original = x[i];
                    vector<char> available = { 'A',
                        'C',
                        'G',
                        'T' };
                    for (int j = 0; j < available.size(); j++)
                    {

                        x[i] = available[j];
                        if (mp.find(x) != mp.end() && mp1.find(x) == mp1.end())
                        {

                            q.push(make_pair(x, topElement.second + 1));
                            mp1[x]++;
                        }
                    }
                    x[i] = original;
                }
            }
            return -1;
        }
};