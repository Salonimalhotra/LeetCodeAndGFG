// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool compare(Job a1,Job a2){
    return a1.profit>a2.profit;
}
int max_deadline(Job arr[],int n){
    int max_ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i].dead>max_ans){
            max_ans=arr[i].dead;
        }
    }
    return max_ans;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,compare);
        vector<int>ans;
        int max_deadline_ans=max_deadline(arr,n);
        
        int JobsIdsCompleted[max_deadline_ans+1];
        for(int i=0;i<=max_deadline_ans;i++){
            JobsIdsCompleted[i]=-1;
        }
        
        int numberJobs=0;
        int max_profit=0;
        for(int i=0;i<n;i++){
            
             for(int j=arr[i].dead;j>0;j--){
                 if(JobsIdsCompleted[j]==-1){
                     JobsIdsCompleted[j]=arr[i].id;
                     numberJobs++;
                     max_profit+=arr[i].profit;
                     break;
                 }
             }
        }
        ans.push_back(numberJobs);
        ans.push_back(max_profit);
        return ans;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends