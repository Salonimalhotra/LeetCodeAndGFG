// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
     int nextGap(int gap)
   {
       if (gap <= 1)
           return 0;
    //   return (gap / 2) + (gap % 2);
    return (int)ceil(gap/2.0);
   }
void merge(int arr1[], int arr2[], int n, int m) {
    // code here
    int i, j, gap = n + m;
       for (gap = nextGap(gap);gap > 0; gap = nextGap(gap))
       {
           i=0;
           j=i+gap;
           while(i<n+m && j<n+m){
               if(i<n && j<n){
                   if(arr1[i]>arr1[j]){
                       swap(arr1[i],arr1[j]);
                   }
                   i++;
                   j++;
               }
               else if(i<n && j>=n){
                   if(arr1[i]>arr2[(j-n)%m]){
                       swap(arr1[i],arr2[(j-n)%m]);
                       
                   }
                   i++;
                   j++;
               }
               else if(i>=n && j>=n){
                   if(arr2[(i-n)%m]>arr2[(j-n)%m]){
                       swap(arr2[(i-n)%m],arr2[(j-n)%m]);
                   }
                   i++;
                   j++;
               }
               
           }
       }
       return; 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends