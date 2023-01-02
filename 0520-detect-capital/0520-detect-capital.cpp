class Solution
{
    public:
        bool detectCapitalUse(string word)
        {
            bool first_upper_case = false;
            if (word[0] >= 'a' && word[0] <= 'z')
            {
                first_upper_case = false;
            }
            else
            {
                first_upper_case = true;
            }

            bool upper_case = true;
            for (int i = 1; i < word.size(); i++)
            {
                if (word[i] >= 'A' && word[i] <= 'Z')
                {
                    continue;
                }
                else
                {
                    upper_case = false;
                    break;
                }
            }

            bool lower_case = true;
            for (int i = 1; i < word.size(); i++)
            {
                if (word[i] >= 'a' && word[i] <= 'z')
                {
                    continue;
                }
                else
                {
                    lower_case = false;
                    break;
                }
            }

            if (first_upper_case == true)
            {
                if (upper_case == true) return true;
                else if (lower_case == true) return true;
                else
                {
                    return false;
                }
            }
            else
            {
                if (lower_case == true)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
};