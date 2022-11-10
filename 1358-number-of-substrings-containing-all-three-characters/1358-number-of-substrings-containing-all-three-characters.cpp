class Solution
{
    public:
        int numberOfSubstrings(string s)
        {
           	// O(N^2 Approach)
           	//             int cnt = 0;
           	//             for (int i = 0; i < s.size(); i++)
           	//             {
           	//                 int acount = 0;
           	//                 int bcount = 0;
           	//                 int ccount = 0;
           	//                 for (int j = i; j < s.size(); j++)
           	//                 {
           	//                     if (s[j] == 'a') acount++;

           	//                     else if (s[j] == 'b') bcount++;

           	//                     else if (s[j] == 'c') ccount++;

           	//                     if (acount >= 1 && bcount >= 1 && ccount >= 1) cnt++;
           	//                 }
           	//             }
           	//             return cnt;
            unordered_map<char, int> mp;
            int i = 0;
            int j = 0;
            int cnt = 0;
            int n=s.size();
            while (j < s.size())
            {
                mp[s[j]]++;

                if (mp.size() < 3)
                {
                    j++;
                }
                else
                {
                    while (mp.size() == 3)
                    {
                        mp[s[i]]--;
                        if (mp[s[i]] == 0) mp.erase(s[i]);
                        i++;
                         cnt+=n-j;
                    }
                  
                    j++;
                }
            }
          return cnt;
        }
};