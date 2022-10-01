class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
      //   int bitwiseAnd=left;
      // for(int i=left+1;i<=right;i++){
      //   bitwiseAnd=bitwiseAnd & i;
      // }
      // return bitwiseAnd;
      if(left==0) return 0;
      int cnt=0;
      while(left!=right){
        left=left>>1;
        right=right>>1;
        cnt++;
      }
      return left<<cnt;
           
    }
};