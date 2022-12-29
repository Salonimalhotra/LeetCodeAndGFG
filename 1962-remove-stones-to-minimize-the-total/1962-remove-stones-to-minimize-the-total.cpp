class cmp
{
  public: 
  bool operator()(int x1, int x2)
    {
        if (x1 < x2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class Solution
{
    public:

        int minStoneSum(vector<int> &piles, int k)
        {
            priority_queue<int, vector < int>, cmp> pq;
            for (int i = 0; i < piles.size(); i++)
            {
                pq.push(piles[i]);
            }
            while (k != 0)
            {
                int x = pq.top();
                pq.pop();
                int y = (x / 2);
                pq.push(x - y);
                k--;
            }
            int sum = 0;
            while (pq.size() != 0)
            {
                sum += pq.top();
                pq.pop();
            }
            return sum;
        }
};