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

#include<bits/stdc++.h>
int binarySearch(int arr[],int s,int e,int x){
    if(s>e){
        return -1;
    }
    int start=s;
    int end=e;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]<x){
          start=mid+1;
        }
        else if(arr[mid]>x){
            end=mid-1;
        }
    }
    return -1;
}
bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    bool check=false;
    for(int i=0;i<=size-2;i++){
        int x=arr[i]+n;
        // int y=arr[i]-n;
        int bS=binarySearch(arr,i+1,size-1,x);
        if(bS==-1){
            continue;
        }
        else{
            check=true;
            break;
        }
    }
    return check;
    
}