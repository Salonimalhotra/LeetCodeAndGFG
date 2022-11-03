class Solution
{
    public:
        bool lemonadeChange(vector<int> &bills)
        {
            unordered_map<int, int> mp;
            for (int i = 0; i < bills.size(); i++)
            {
                if (bills[i] == 5)
                {
                    mp[5]++;
                }
                else if (bills[i] == 10)
                {
                    if (mp.find(5) == mp.end())
                    {
                        // cout << i << endl;
                        return false;
                    }
                    else
                    {
                        mp[5]--;
                        if (mp[5] == 0) mp.erase(5);
                        mp[10]++;
                        continue;
                    }
                }
                else
                {
                    if (mp.find(5) == mp.end())
                    {
                        // cout << i << endl;
                        return false;
                    }
                    if (mp.find(10) == mp.end())
                    {
                        if (mp[5] < 3)
                        {
                            return false;
                        }
                        else
                        {
                            mp[5]--;
                            mp[5]--;
                            mp[5]--;
                            if (mp[5] == 0) mp.erase(5);
                        }
                    }
                    else
                    {
                        mp[20]++;
                        mp[5]--;
                        if (mp[5] == 0) mp.erase(5);
                        mp[10]--;
                        if (mp[10] == 0) mp.erase(10);
                    }
                }
            }
            return true;
        }
};