class Solution
{
    public:
        bool halvesAreAlike(string s)
        {
            string s1 = s.substr(0, s.size() / 2);
            string s2 = s.substr(s.size() / 2, s.size() / 2);
            int cnt1 = 0;
            int cnt2 = 0;
            for (int i = 0; i < s1.size(); i++)
            {
                if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u' || s1[i] == 'A' || s1[i] == 'E' || s1[i] == 'I' || s1[i] == 'O' || s1[i] == 'U')
                {
                    cnt1++;
                }
            }

            for (int i = 0; i < s2.size(); i++)
            {
                if (s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u' || s2[i] == 'A' || s2[i] == 'E' || s2[i] == 'I' || s2[i] == 'O' || s2[i] == 'U')
                {
                    cnt2++;
                }
            }
            if (cnt1 == cnt2) return true;
            return false;
        }
};