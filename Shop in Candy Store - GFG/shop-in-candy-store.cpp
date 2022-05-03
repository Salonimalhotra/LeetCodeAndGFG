// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    bool static compare(int x,int y){
        return x<y;
    }
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N,compare);
        // for(int i=0;i<N;i++){
        //     cout<<candies[i]<<endl;
        // }
        int min_amount_money=0;
        int candiesBought=0;
        for(int i=0;i<N;i++){
            min_amount_money+=candies[i];
             candiesBought=candiesBought+1+K;
            if(candiesBought>=N){
                break;
            }
            
        }
        vector<int>ans;
        ans.push_back(min_amount_money);
        int max_amount_money=0;
        candiesBought=0;
        for(int i=N-1;i>=0;i--){
            max_amount_money+=candies[i];
            candiesBought=candiesBought+1+K;
            if(candiesBought>=N){
                break;
            }
        }
        ans.push_back(max_amount_money);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends