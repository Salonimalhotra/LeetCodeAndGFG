// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}// } Driver Code Ends

#include<bits/stdc++.h>
#include<climits>
pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long ,long long>ans;
    long  minNum=INT_MAX;
    long  maxNum=INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]<minNum){
            minNum=a[i];
        }
        if(a[i]>maxNum){
            maxNum=a[i];
        }
    }
    ans.first=minNum;
    ans.second=maxNum;
    return ans;
}