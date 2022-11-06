class Solution
{
    public:
       	//         int helper(vector<int> &cardPoints, int k, int start, int end, unordered_map<string, int> &mp)
       	//         {
       	//             if (k == 0 || start > end)
       	//             {
       	//                 return 0;
       	//             }

       	//             string key = "";
       	//             key.append(to_string(k));
       	//             key.push_back(' ');
       	//             key.append(to_string(start));
       	//             key.push_back(' ');
       	//             key.append(to_string(end));

       	//             if (mp.find(key) != mp.end())
       	//             {
       	//                 return mp[key];
       	//             }

       	//             int option1 = cardPoints[start] + helper(cardPoints, k - 1, start + 1, end, mp);
       	//             int option2 = cardPoints[end] + helper(cardPoints, k - 1, start, end - 1, mp);
       	//             return mp[key] = max(option1, option2);
       	//         }
        int maxScore(vector<int> &cardPoints, int k)
        {
           	// unordered_map<string, int> mp;
           	// return helper(cardPoints, k, 0, cardPoints.size() - 1, mp);
            int i = 0;
            int j = 0;
            int maxAns = INT_MIN;
            int sum = 0;
            int totalPoints = 0;

            for (int i = 0; i < cardPoints.size(); i++)
            {
                totalPoints += cardPoints[i];
            }

            if (k >= cardPoints.size())
            {
                return totalPoints;
            }
            int window = cardPoints.size() - k;
            while (j < cardPoints.size())
            {
                sum += cardPoints[j];
                if (j - i + 1 < window)
                {
                    j++;
                }
                else if (j - i + 1 == window)
                {
                    maxAns = max(maxAns, totalPoints - sum);
                    sum -= cardPoints[i];
                    i++;
                    j++;
                }
            }

            return maxAns;
        }
};