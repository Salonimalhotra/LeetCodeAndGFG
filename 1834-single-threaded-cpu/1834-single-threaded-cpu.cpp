// class cmp
// {
//     public:
//         bool operator()(pair<int, int> p1, pair<int, int> p2)
//         {
//             if (p1.second > p2.second)
//             {
//                 return true;
//             }
//             else if (p1.second == p2.second)
//             {
//                 if (p1.first > p2.first)
//                 {
//                     return true;
//                 }
//                 else
//                 {
//                     return false;
//                 }
//             }
//             return false;
//         }
// };
class Solution
{
    public:
        vector<int> getOrder(vector<vector < int>> &tasks)
        {
            priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int,int>>> pq;
            vector<int> ans;
            vector<vector < int>> v = tasks;
            for (int i = 0; i < tasks.size(); i++)
            {
                v[i].push_back(i);
            }
            sort(v.begin(), v.end());

            long long  timer = v[0][0];
            int i = 0;
            while (i < v.size() || pq.size()!=0)
            {
                if (i < v.size() && v[i][0] <= timer)
                {
                    while (i < v.size() && v[i][0] <= timer)
                    {
                        pq.push(make_pair(v[i][1], v[i][2]));
                        i++;
                    }
                }
                else
                {
                    if (pq.size() == 0)
                    {
                        timer = v[i][0];
                    }
                    else
                    {
                        ans.push_back(pq.top().second);
                        timer += pq.top().first;
                        pq.pop();
                    }
                }
            }
            return ans;
        }
};