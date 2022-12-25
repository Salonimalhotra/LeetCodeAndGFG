class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
      int n=words.size();  
      int closest=INT_MAX;
        if(words[startIndex]==target){
          return 0;
        }
        int i=(startIndex-1+n)%n;
        for(int j=i;j!=startIndex;j=(j-1+n)%n){
          if(words[j]==target){
            closest=min(closest,abs(j-startIndex));
            closest=min(closest,n-abs(j-startIndex));
          }
        }
        i=(startIndex+1)%n;
        for(int j=i;j!=startIndex;j=(j+1)%n){
          if(words[j]==target){
            closest=min(closest,abs(j-startIndex));
            closest=min(closest,n-abs(j-startIndex));
          
          }
        }
      if(closest==INT_MAX) return -1;
      return closest;
    }
};