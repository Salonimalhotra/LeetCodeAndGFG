class Solution
{
    public:
        int maxDistToClosest(vector<int> &seats)
        {
            vector<int> ans1(seats.size(), 0);
            vector<int> ans2(seats.size(), 0);
            int first = -1;
            for (int i = 0; i < seats.size(); i++)
            {
                if (seats[i] == 1)
                {
                    first = i;
                    continue;
                }
                else
                {
                    ans1[i] = i - first;
                }
            }
            int end = seats.size();
            for (int i = seats.size() - 1; i >= 0; i--)
            {
                if (seats[i] == 1)
                {
                    end = i;
                    continue;
                }
                else
                {
                    ans2[i] = end - i;
                }
            }

            int maxDis = INT_MIN;
            for (int i = 0; i < seats.size(); i++)
            {
                if (seats[i] == 0)
                {
                    if (i == 0 || i == seats.size() - 1)
                    {
                        maxDis = max(maxDis, max(ans1[i], ans2[i]));
                    }
                    else maxDis = max(maxDis, min(ans1[i], ans2[i]));
                }
            }
            return maxDis;
        }
};