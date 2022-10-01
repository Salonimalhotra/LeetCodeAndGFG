class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int minAns=0;
        int start=1;
        if(maxDoubles==0) return target-1;
        else if(target==1) return 0;
        while(start!=target){
             if(maxDoubles!=0 && target%2==0 && target/2>=start){
                 target=target/2;
                 maxDoubles--;
                 minAns++;
             }
             else{
                target=target-1;
                minAns++;
             }
        }
      return minAns;
    }
};