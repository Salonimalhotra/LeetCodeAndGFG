class Solution {
public:
    
    int countPrimes(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 0;
        }
        if(n==2){
            return 0;
        }
      bool arr[n+1];
        for(int i=0;i<=n;i++){
            arr[i]=true;
        }
        arr[0]=false;
        arr[1]=false;
        for(int i=2;i*i<=n;i++){
            for(int j=2*i;j<=n;j+=i){
                arr[j]=false;
            }
        }
        
        int count=0;
        for(int i=2;i<n;i++){
            if(arr[i]==true){
                count++;
            }
        }
        return count;
    }
};