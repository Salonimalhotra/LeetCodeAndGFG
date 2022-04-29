#include<string>
#include<unordered_map>
class Solution {
public:
   bool solve(string A,string B,unordered_map<string,bool>&map){
    if(A.compare(B)==0){
        return true;
    }
    if(A.length()<=1){
        return false;
    }
       
    string x;
    x.append(A);
    x.append(" ");
    x.append(B);
    
    if(map.find(x)!=map.end()){
        return map[x];
    }   
    
    bool flag=false;
    int n=B.size();
    for(int i=1;i<n;i++){
       bool condition1=solve(A.substr(0,i),B.substr(0,i),map) && solve(A.substr(i,n-i),B.substr(i,n-i),map);            bool condition2=solve(A.substr(0,i),B.substr(n-i,i),map) && solve(A.substr(i,n-i),B.substr(0,n-i),map);
        if(condition1 || condition2){
            flag=true;
            break;
        }
    }
       
    map[x]=flag;   
    return flag;
}
    bool isScramble(string s1, string s2) {
       if(s1.length()!=s2.length()){
        return false;
    }
     if(s1.length()==0 && s2.length()==0){
        return true;
    }
    unordered_map<string,bool>map;
    bool ans=solve(s1,s2,map);
        return ans;
    }
};