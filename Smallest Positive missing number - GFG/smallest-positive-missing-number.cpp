//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        // */
        //     0 1 -10 3 -20
            
        // */
        
         int i=0;
         while(i<n){
             int correct_pos=arr[i]-1;
             if(correct_pos>=0 && correct_pos<n && arr[correct_pos]!=arr[i]){
                 swap(arr[i],arr[correct_pos]);
             }
             else{
                 i++;
             }
             
         }
          
         int missingnum=-1;
         for(int i=0;i<n;i++){
             if(arr[i]!=i+1){
                 missingnum=i+1;
                 break;
             }
         }
         if(missingnum==-1)missingnum=n+1;
        return missingnum;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends