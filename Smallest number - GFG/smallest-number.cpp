// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        if(S==0){
            if(D==1){
                string ans="0";
                return ans;
            }
            else if(D>1){
                string ans="-1";
                return ans;
            }
        }
        
        else if(9*D<S){
            string ans="-1";
            return ans;
        }
        
        string ans="";
        int i=D;
        int sum=S;
        while(i!=0){
           int num=9;
           if(i>1){
            while(num>=sum){
               num--;
             }    
           }
           else{
               while(num>sum){
                   num--;
               }
           }
           
           char num_c=num+'0';
        //   cout<<num_c<<endl;
           ans=num_c+ans;
           sum-=num;
           i--;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends