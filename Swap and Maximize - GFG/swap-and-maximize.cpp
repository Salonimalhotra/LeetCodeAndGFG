// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    int arr1[n];
    for(int i=0;i<n;i++){
        arr1[i]=arr[i];
    }
    
    int arr2[n];
    sort(arr,arr+n,greater<int>());
     for(int i=0;i<n;i++){
        arr2[i]=arr[i];
    }
    int finalArr[n];
    int i=0;
    int j=0;
    int m=0;
    while(m!=n){
        if(m%2==0){
            finalArr[m]=arr1[i];
            i++;
        }
        else{
            finalArr[m]=arr2[j];
            j++;
        }
        m++;
    }
    long long int sum=0;
    for(int i=0;i<=n-2;i++){
        sum+=abs(finalArr[i]-finalArr[i+1]);
    }
    sum+=abs(finalArr[n-1]-finalArr[0]);
    return sum;
    
}