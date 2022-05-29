// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void merge(int a[],int start,int end){
        int mid=(start+end)/2;
        int i=start;
        int j=mid+1;
        int arr[end-start+1];
        int k=0;
        while(i<=mid && j<=end){
            if(a[i]<=a[j]){
                arr[k]=a[i];
                k++;
                i++;
            }
            else{
                arr[k]=a[j];
                k++;
                j++;
            }
        }
        
        while(i<=mid){
            arr[k++]=a[i++];
        }
        
        while(j<=end){
            arr[k++]=a[j++];
        }
        k=0;
        for(int i=start;i<=end;i++){
            a[i]=arr[k++];
        }
        return;
    }
    void mergeSort(int a[],int start,int end){
        if(start>=end){
            return;
        }
        int mid=(start+end)/2;
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);
        merge(a,start,end);
        return;
    }
    void sort012(int a[], int n)
    {
        // coode here 
        mergeSort(a,0,n-1);
        return;
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends