class Solution
{
    public:
        bool isPalindrome(string s, int i, int j)
        {
            if (i > j) return false;

            while (i <= j)
            {
                if (s[i] != s[j]) return false;                
                    i++;
                    j--;
                
                
            }
            return true;
        }
    void helper(vector<vector < string>> &ans, vector< string > &ans1, int i, string s)
    {
        if (i == s.size())
        {
            ans.push_back(ans1);
            return;
        }

        for (int start = i; start <s.size(); start++)
        {
            if (isPalindrome(s, i, start))
            {
                ans1.push_back(s.substr(i, start-i+1));
                helper(ans, ans1, start + 1, s);
                ans1.pop_back();
            }
        }
      return;
    }

    vector<vector < string>> partition(string s)
    {
        vector<vector < string>> ans;
        vector<string> ans1;
        helper(ans,ans1,0,s);
        return ans;
    }
};