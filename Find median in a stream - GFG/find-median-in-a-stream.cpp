// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    //Function to insert heap.
    public:
    void insertHeap(int &x)
    {
         if(maxHeap.size()!=0 &&  maxHeap.top()<x){
            minHeap.push(x);
        }
        else {
            maxHeap.push(x);
        }
        
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
     
       if(minHeap.size()>maxHeap.size() && minHeap.size()-maxHeap.size()>1){
            int topElement=minHeap.top();
            minHeap.pop();
            maxHeap.push(topElement);
        }
        else if(minHeap.size()<maxHeap.size() && maxHeap.size()-minHeap.size()>1){
            int topElement=maxHeap.top();
            maxHeap.pop();
            minHeap.push(topElement);
        }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
         double median=0;
        if(minHeap.size()==maxHeap.size()){
            if(minHeap.size()!=0){
                median+=minHeap.top();
            }
            if(maxHeap.size()!=0){
                median+=maxHeap.top();
            }
            median=median/2;
        }
        
        else if(minHeap.size()>maxHeap.size()){
            median=minHeap.top();
        }
        else if(maxHeap.size()>minHeap.size()){
            median=maxHeap.top();
        }
        
        return median;
        
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends