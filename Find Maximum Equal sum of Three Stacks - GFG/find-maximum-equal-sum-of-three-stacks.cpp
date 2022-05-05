// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
#include<vector>
class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int s1=0;
        for(int i=0;i<S1.size();i++){
            s1+=S1[i];
        }
        int s2=0;
        for(int i=0;i<S2.size();i++){
            s2+=S2[i];
        }
        int s3=0;
        for(int i=0;i<S3.size();i++){
            s3+=S3[i];
        }
        
        int top1=0;
        int top2=0;
        int top3=0;
        
        while(true){
            if(top1==N1 || top2==N2 || top3==N3){
                return 0;
            }
            if(s1==s2 && s2==s3){
                return s1;
            }
            if(s1>=s2 && s1>=s3){
                s1-=S1[top1];
                top1=top1+1;
            }
            else if(s2>=s3 && s2>=s1){
                s2-=S2[top2];
                top2++;
            }
            else if(s3>=s1 && s3>=s1){
                s3-=S3[top3];
                top3++;
            }
            
        }
        return 0;
        
        
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}  // } Driver Code Ends