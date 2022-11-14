class Solution
{
    public:
        bool isPossibleDivide(vector<int> &nums, int k)
        {
           	//             unordered_map<int, int> mp;
           	//             sort(hand.begin(), hand.end());
           	//             for (int i = 0; i < hand.size(); i++)
           	//             {
           	//                 if (mp.find(i) != mp.end()) continue;
           	//                 else
           	//                 {
           	//                     int startIndex = i;
           	//                     int cnt = 1;
           	//                     mp[startIndex]++;
           	//                     startIndex++;
           	//                     int last = i;
           	//                     while (startIndex < hand.size() && cnt != groupSize)
           	//                     {
           	//                         if (mp.find(startIndex) == mp.end() && (hand[startIndex] == hand[last] + 1))
           	//                         {

           	//                             mp[startIndex]++;
           	//                             cnt++;
           	//                             last = startIndex;
           	//                             startIndex++;
           	//                         }
           	//                         else if ((hand[startIndex] > hand[last] + 1)) break;

           	//                         else startIndex++;
           	//                     }
           	//                     if (cnt != groupSize) return false;
           	//                 }
           	//             }
           	//             if (mp.size() == hand.size()) return true;
           	//             else return false;
            multiset<int> mp;
            for (auto i: nums)
            {
                mp.insert(i);
            }

            while (mp.size() != 0)
            {
                int first = *mp.begin();
                int temp = 0;
                int next=first+1;
                mp.erase(mp.begin());                
                while (temp != k - 1)
                {
                    if (mp.find(next) == mp.end())
                    {
                        return false;
                    }
                    mp.erase(mp.find(next));
                    next++;
                    temp++;
                }
            }
            return true;
        }
};