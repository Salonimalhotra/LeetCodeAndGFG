// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends

int binarySearch(int arr[],int s,int e,int x){
    int i=s;
    int j=e;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]<x){
            i=mid+1;
        }
        else if(arr[mid]>x){
            j=mid-1;
        }
    }
    return -1;
}
bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    for(int i=0;i<size;i++){
        //arr[i]-x=n => x=arr[i]-n 
        //x-arr[i]=n => x=n+arr[i]
        if(binarySearch(arr,i+1,size-1,arr[i]-n)!=-1 || binarySearch(arr,i+1,size-1,n+arr[i])!=-1){
            return true;
        }
    }
    return false;
    
}