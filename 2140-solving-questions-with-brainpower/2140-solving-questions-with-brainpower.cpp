class Solution
{
    public:
        // long long helper(vector<vector < int>> &questions, int index)
        // {
        //     if (index >= questions.size())
        //     {
        //         return 0;
        //     }
        //     long long option1 = questions[index][0] + helper(questions, index + questions[index][1] + 1);
        //     long long option2 = helper(questions, index + 1);
        //     return max(option1, option2);
        // }
    long long mostPoints(vector<vector < int>> &questions)
    {
        vector<long long> dp(questions.size() + 1, 0);
        for (int i = questions.size() - 1; i >= 0; i--)
        {
              long long  option1 = dp[i + 1];
              long long  option2 = INT_MIN;
            if (i + 1 + questions[i][1] >= questions.size())
            {
                option2 = questions[i][0];
            }
            else if(i+1 + questions[i][1]<=questions.size()){
              option2=questions[i][0] + + dp[i + 1 + questions[i][1]];
            }
            dp[i] = max(option1, option2);
        }
     
        return dp[0];
    }
};