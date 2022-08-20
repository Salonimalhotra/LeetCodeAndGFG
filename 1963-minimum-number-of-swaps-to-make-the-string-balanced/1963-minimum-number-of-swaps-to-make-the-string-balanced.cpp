#include<string>
class Solution {
public:
      int minSwaps(string s) {
          int cntO=0;
          int cntC=0;
          int i=0;
          int j=s.size()-1;
          int minS=0;
          stack<char>s1;
          while(i<j){
             if(s[i]=='['){
                 cntO++;
             }
             else if(s[i]==']'){
               cntC++;
             }
             
             if(cntC>cntO){
                 while(s[j]!='['){
                     j--;
                 }
                 // swap(s[i],s[j]);
                 char temp=s[i];
                 s[i]=s[j];
                 s[j]=temp;
                 cntC--;
                 cntO++;
                 minS++;
                 i++;
                 j--;
             }
             else{
                 i++;
             }
              
          }
         return minS; 
    }
};