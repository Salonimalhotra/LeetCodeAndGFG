class Solution
{
    public:
        int compress(vector<char> &chars)
        {
            vector<char> finalans;
            int i = 0;
            int j = 0;
            while (j < chars.size())
            {
                if (chars[j] == chars[i])
                {
                    j++;
                }
                else if (chars[j] != chars[i])
                {
                    string num = "";
                    if (j - i == 1)
                    {
                        finalans.push_back(chars[i]);
                    }
                    else if (j - i >= 2 && j - i <= 9)
                    {
                        finalans.push_back(chars[i]);
                        finalans.push_back((j - i) + '0');
                    }
                    else
                    {
                        int n = j - i;
                        finalans.push_back(chars[i]);
                        while (n != 0)
                        {
                            num.push_back(n % 10 + '0');
                            n = n / 10;
                        }
                        reverse(num.begin(), num.end());
                        for (int i = 0; i < num.size(); i++)
                        {
                            finalans.push_back(num[i]);
                        }
                    }
                    i = j;
                    j++;
                }
            }

            string num = "";
            if (j - i == 1)
            {
                finalans.push_back(chars[i]);
            }
            else if (j - i >= 2 && j - i <= 9)
            {
                finalans.push_back(chars[i]);
                finalans.push_back((j - i) + '0');
            }
            else
            {
                int n = j - i;
                finalans.push_back(chars[i]);
                while (n != 0)
                {

                    num.push_back(n % 10 + '0');
                    n = n / 10;
                }
                reverse(num.begin(), num.end());
                for (int i = 0; i < num.size(); i++)
                {
                    finalans.push_back(num[i]);
                }
            }
            chars = finalans;
            return chars.size();
        }
};