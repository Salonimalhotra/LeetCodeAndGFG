// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
bool compare(int a,int b){
    return a>b;
}
class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        int arr[10]={1,2,5, 10,20,50,100,200,500,2000};
        int n=10;
        // sort(arr,arr+10,compare);
        vector<int>ans;
        int currentValue=N;
        for(int i=n-1;i>=0;i--){
            while(arr[i]<=currentValue){
                ans.push_back(arr[i]);
                currentValue=currentValue-arr[i];
                if(currentValue==0){
                    break;
                }
            }
            if(currentValue==0){
                break;
            }
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends