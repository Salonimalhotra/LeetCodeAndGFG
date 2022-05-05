// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#include<unordered_map>
class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        unordered_map<int,int>currMemory;
        int pgf=0;
        for(int i=0;i<N;i++){
            if(currMemory.size()<C){
                if(currMemory.find(pages[i])!=currMemory.end()){
                    currMemory[pages[i]]=i;
                    continue;
                }
                else{
                    pgf++;
                   currMemory[pages[i]]=i;
                }
            }
            else if(currMemory.size()>=C){
                if(currMemory.find(pages[i])!=currMemory.end()){
                   currMemory[pages[i]]=i;
                }
                else{
                    int least_recently=-1;
                    int min1=INT_MAX;
                    for(auto i:currMemory){
                        if(i.second<min1){
                            least_recently=i.first;
                            min1=i.second;
                        }
                    }
                    currMemory.erase(least_recently);
                    currMemory[pages[i]]=i;
                     pgf++;
                }
            }    
        }
        return pgf;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends