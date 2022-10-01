class Solution {
public:
    int minMoves(int target, int maxDoubles) {
              if(maxDoubles==0) return target-1;

               int minAns=0;
               int start=1;
      
        while(start!=target){
             if(maxDoubles!=0 && target%2==0 && target/2>=start){
                 target=target/2;
                 maxDoubles--;
                
             }
             else target=target-1;
               
             minAns++;
        }
      return minAns;
    }
};