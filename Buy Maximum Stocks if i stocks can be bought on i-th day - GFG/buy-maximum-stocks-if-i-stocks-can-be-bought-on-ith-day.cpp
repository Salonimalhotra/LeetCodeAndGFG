// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool static compare(pair<int,int>p1,pair<int,int>p2){
        return p1.second<p2.second;
    }
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            pair<int,int>p1=make_pair(i+1,price[i]);
            arr.push_back(p1);
        }
        sort(arr.begin(),arr.end(),compare);
        // for(int i=0;i<arr.size();i++){
        //     cout<<arr[i].first<<" "<<arr[i].second<<" "<<endl;
        // }
        int max_stocks=0;
        int currMoney=k;
        for(int i=0;i<arr.size();i++){
            while(currMoney!=0 && arr[i].second<=currMoney && arr[i].first!=0){
                arr[i].first=arr[i].first-1;
                max_stocks++;
                currMoney-=arr[i].second;
            }
            if(currMoney==0){
                break;
            }
        }
        return max_stocks;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends