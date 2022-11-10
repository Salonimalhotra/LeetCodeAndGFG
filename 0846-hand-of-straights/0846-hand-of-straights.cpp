class Solution
{
    public:
        bool isNStraightHand(vector<int> &hand, int groupSize)
        {
            vector<vector < int>> v;
            unordered_map<int, int> mp;
            sort(hand.begin(), hand.end());
            for (int i = 0; i < hand.size(); i++)
            {
                if (mp.find(i) != mp.end())
                {
                    continue;
                }
                else
                {
                    int startIndex = i;
                    vector<int> ans;
                    ans.push_back(i);
                    int cnt = 1;
                    mp[startIndex]++;
                    startIndex++;
                    int last = i;
                    while (startIndex < hand.size() && cnt != groupSize)
                    {
                        if (mp.find(startIndex) == mp.end() && (hand[startIndex] == hand[last] + 1))
                        {
                            ans.push_back(startIndex);
                            mp[startIndex]++;
                            cnt++;
                            last = startIndex;
                            startIndex++;
                        }
                        else
                        {
                            startIndex++;
                        }
                    }

                    if (ans.size() != groupSize) return false;
                    v.push_back(ans);
                }
            }
            if (mp.size() == hand.size())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};