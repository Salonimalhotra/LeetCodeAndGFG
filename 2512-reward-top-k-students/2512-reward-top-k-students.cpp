class cmp
{
    public:
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }
};
class Solution
{
    public:

        vector<int> topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector< string > &report, vector< int > &student_id, int k)
        {
            priority_queue<pair<int, int>, vector< pair<int, int>>, cmp> pq;
            unordered_map<string, int> positive;
            unordered_map<string, int> negative;
            for (int i = 0; i < positive_feedback.size(); i++)
            {
                positive[positive_feedback[i]]++;
            }
            for (int i = 0; i < negative_feedback.size(); i++)
            {
                negative[negative_feedback[i]]++;
            }
            for (int i = 0; i < report.size(); i++)
            {
                int score = 0;
                string x1 = "";
                for (int j = 0; j < report[i].size(); j++)
                {
                    if (report[i][j] == ' ')
                    {
                        if (positive.find(x1) != positive.end())
                        {
                            score += 3;
                        }
                        else if (negative.find(x1) != negative.end())
                        {
                            score -= 1;
                        }
                        x1 = "";
                    }
                    else
                    {
                        x1.push_back(report[i][j]);
                    }
                }
                if (positive.find(x1) != positive.end())
                {
                    score += 3;
                }
                else if (negative.find(x1) != negative.end())
                {
                    score -= 1;
                }
                pq.push(make_pair(score, student_id[i]));
                
            }

            
            vector<int> ans;
            int cnt=0;
            while (pq.size() !=0 && cnt!=k)
            {
                ans.push_back(pq.top().second);
                cnt++;
                pq.pop();
            }
           	// reverse(ans.begin(),ans.end());
            return ans;
        }
};