// { Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++
#include<vector>
#include<bits/stdc++.h>
class Solution{
    public:
    void heapify(vector<int>&a,int i){
        int max_index=i;
        int leftIndex=2*i+1;
        int rightIndex=2*i+2;
        
        if(leftIndex<a.size() && a[leftIndex]>a[max_index]){
            max_index=leftIndex;
        }
        
        if(rightIndex<a.size() && a[rightIndex]>a[max_index]){
            max_index=rightIndex;
        }
        
        if(i!=max_index){
            int temp=a[i];
            a[i]=a[max_index];
            a[max_index]=temp;
            heapify(a,max_index);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        for(int i=0;i<b.size();i++){
            a.push_back(b[i]);
        }
        
        int n1=a.size();
        for(int i=(n1-1)/2;i>=0;i--){
            heapify(a,i);
        }
        
        return a;
        
    }
};

// { Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}
  // } Driver Code Ends