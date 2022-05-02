// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool static compare(Item a1,Item a2){
    double valByweight1=(double)a1.value/(double)a1.weight;
    double valByweight2=(double)a2.value/(double)a2.weight;
    if(valByweight1>valByweight2){
        return true;
    }
    else{
        return false;
    }
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,compare);
        int currWeight=0;
        double totalValue=0;
        int i=0;
        while(i<n){
            if(arr[i].weight+currWeight<=W){
                totalValue+=arr[i].value;
                currWeight=arr[i].weight+currWeight;
                i++;
            }
            else if(arr[i].weight+currWeight>W){
                int remainingWeight=W-currWeight;
                double valueExtra=((double)arr[i].value/(double)arr[i].weight)*remainingWeight;
                totalValue+=valueExtra;
                break;
            }
        }
        return totalValue;
        
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends