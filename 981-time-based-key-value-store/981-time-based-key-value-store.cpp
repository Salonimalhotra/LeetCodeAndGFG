class TimeMap
{
    public:
        unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp)
    {
        if (mp[key].size() == 0) return "";

        int start = 0;
        int end = mp[key].size()-1;
        string value;
        while (start <= end)
        {
            int mid = (start + (end - start) / 2);
            if (mp[key][mid].first == timestamp)
            {
                return mp[key][mid].second;
            }
            else if (mp[key][mid].first < timestamp)
            {
                value = mp[key][mid].second;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return value;
    }
};

/**
 *Your TimeMap object will be instantiated and called as such:
 *TimeMap* obj = new TimeMap();
 *obj->set(key,value,timestamp);
 *string param_2 = obj->get(key,timestamp);
 */