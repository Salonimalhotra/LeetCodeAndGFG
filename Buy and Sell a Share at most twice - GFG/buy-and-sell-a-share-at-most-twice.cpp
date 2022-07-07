// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    //Write your code here..
    int n=price.size();
    int profit[price.size()];
    profit[n-1]=0;
    int maxElement=price[n-1];
    for(int i=n-2;i>=0;i--){
        if(price[i]>maxElement){
            maxElement=price[i];
        }
        int option1=maxElement-price[i];
        int option2=profit[i+1];
        profit[i]=max(option1,option2);
    }
    
    // for(int i=0;i<n;i++){
    //     cout<<profit[i]<<" ";
    // }
    // cout<<endl;
    int minElement=price[0];
    for(int i=1;i<n;i++){
        if(price[i]<minElement){
            minElement=price[i];
        }
        int option1=profit[i-1];
        int option2=price[i]-minElement + profit[i];
        profit[i]=max(option1,option2);
    }
    
    // for(int i=0;i<n;i++){
    //     cout<<profit[i]<<" ";
    // }
    // cout<<endl;
    return profit[n-1];
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends