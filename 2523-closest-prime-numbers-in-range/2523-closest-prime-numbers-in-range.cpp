class Solution {
public:
    bool isPrime(int x){
      if(x<=1){
        return false;
      }
      for(int i=2;i * i<=x;i++){
        if(x%i==0){
          return false;
        }
      }
      return true;
    }
  
    vector<int> closestPrimes(int left, int right) {
        vector<int>primeNumbers;
        for(int i=left;i<=right;i++){
          if(isPrime(i)==true){
            primeNumbers.push_back(i);
          }
        }
        vector<int>ans;
        if(primeNumbers.size()<=1){
          return {-1,-1};
        }
        
       
        int diff=INT_MAX;
        int n1;
        int n2;
        for(int i=0;i<primeNumbers.size()-1;i++){
          if(primeNumbers[i+1]-primeNumbers[i]<diff){
            n1=primeNumbers[i];
            n2=primeNumbers[i+1];
            diff=n2-n1;
          }
        }
      ans.push_back(n1);
      ans.push_back(n2);
      return ans;
    }
};