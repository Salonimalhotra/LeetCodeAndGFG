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

#include<unordered_map>
bool findPair(int arr[], int size, int n){
    //code
    if(n==0){
        unordered_map<int,int>map1;
        for(int i=0;i<size;i++){
            map1[arr[i]]++;
        }
        for(auto i:map1){
            if(i.second>=2){
                return true;
            }
        }
        return false;
    }
    unordered_map<int,int>map;
    for(int i=0;i<size;i++){
        map[arr[i]]=i;
    }
    bool check=false;
    for(int i=0;i<size;i++){
        if((map.find(arr[i]+n)!=map.end()) || (map.find(arr[i]-n)!=map.end())){
            check=true;
            break;
        }
    }
    return check;
    
}