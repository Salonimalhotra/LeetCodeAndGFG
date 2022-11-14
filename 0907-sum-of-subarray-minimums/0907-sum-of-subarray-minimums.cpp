class Solution
{
    public:
        vector<int> findprev_smaller(vector<int> &arr)
        {
            vector<int> ans(arr.size(), -1);
            stack<int> st;
            for (int i = 0; i < arr.size(); i++)
            {
                while (st.size() != 0 && arr[st.top()] > arr[i])
                {
                    st.pop();
                }
                if (st.size())
                {
                    ans[i] = st.top();
                }
                st.push(i);
            }
            return ans;
        }
    vector<int> findnext_smaller(vector<int> &arr)
    {
        vector<int> ans(arr.size(), arr.size());
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            while (st.size() != 0 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (st.size())
            {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int> &arr)
    {
       	// int cnt = 0;
       	// int minAns = 0;
       	// for (int i = 0; i < arr.size(); i++)
       	// {
       	//     for (int j = i; j < arr.size(); j++)
       	//     {
       	//         int minElement = INT_MAX;
       	//         for (int k = i; k <= j; k++)
       	//         {
       	//             minElement = min(minElement, arr[k]);
       	//         }
       	//         minAns += minElement;
       	//     }
       	// }
       	// return minAns;
        int ans = 0;
        int M = 1e9 + 7;
        vector<int> prev = findprev_smaller(arr);
        vector<int> next = findnext_smaller(arr);

        for (int i = 0; i < arr.size(); i++)
        {
            int x = i - prev[i] - 1;
            int y = next[i] - i - 1;
            ans = (ans + ((y + 1) *1LL *(x + 1) *1LL*arr[i]) % M) % M;
        }
        return ans;
    }
};