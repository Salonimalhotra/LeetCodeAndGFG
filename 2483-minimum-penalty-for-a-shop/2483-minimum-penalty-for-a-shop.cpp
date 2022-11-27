class Solution
{
    public:
        int bestClosingTime(string customers)
        {
            int hours = customers.size();
            vector<int> prefix;
            int noCustomers = 0;
            for (int i = 0; i <= customers.size(); i++)
            {
                prefix.push_back(noCustomers);
                if (i < customers.size() && customers[i] == 'N')
                {
                    noCustomers++;
                }
            }

            vector<int> suffix;
            int yescustomers = 0;
            suffix.push_back(yescustomers);
            for (int i = customers.size() - 1; i >= 0; i--)
            {
                if (customers[i] == 'Y')
                {
                    yescustomers++;
                }
                suffix.push_back(yescustomers);
            }
            reverse(suffix.begin(), suffix.end());
          
            // cout << "prefix";
            // for (int i = 0; i < prefix.size(); i++)
            // {
            //     cout << prefix[i] << " ";
            // }
            // cout << endl;
            // cout << "suffix";
            // for (int i = 0; i < suffix.size(); i++)
            // {
            //     cout << suffix[i] << " ";
            // }
            // cout << endl;
          
          
            int best_ans = -1;
            int score = INT_MAX;
            // cout<<prefix.size()<<endl;
            for (int i = 0; i <prefix.size(); i++)
            {
                if ((prefix[i] + suffix[i]) < score)
                {
                    best_ans = i;
                    score = prefix[i] + suffix[i];
                }
            }
            return best_ans;
        }
};