// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void helper(vector<int> &A,int B,vector<vector<int>>&finalAns,vector<int>&path,int i,int size){
        if(size==0){
            if(B==0){
                sort(path.begin(),path.end());
                finalAns.push_back(path);
                return;
            }
            else{
                return;
            }
        }
        if(A[i]<=B){
            path.push_back(A[i]);
            helper(A,B-A[i],finalAns,path,i,size);
            path.pop_back();
            helper(A,B,finalAns,path,i+1,size-1);
        }
        else{
            helper(A,B,finalAns,path,i+1,size-1);
        }
        return;
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        set<int>s;
        for(auto i:A){
            s.insert(i);
        }
        A.clear();
        for(auto i:s){
            A.push_back(i);
        }
        vector<vector<int>>finalAns;
        vector<int>path;
        helper(A,B,finalAns,path,0,A.size());
        sort(finalAns.begin(),finalAns.end());
        return finalAns;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends