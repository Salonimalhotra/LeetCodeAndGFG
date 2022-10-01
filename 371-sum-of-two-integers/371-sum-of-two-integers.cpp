class Solution {
public:
    int getSum(int a, int b) {
        int num=0;
        int carry=0;
        for(int i=0;i<32;i++){
             int m= 1<<i;
             if((a & m)!=0 && (b&m)!=0){
               if(carry==0){
                    num= num & ~(m);
                    carry=1;    
               }
               else if(carry==1){
                   num= num | m;
               }             
             }
            else if((a & m)!=0 || (b&m)!=0){
              if(carry==0)num= num | m;
              else if(carry==1){
                    num= num & ~(m);
                  
              }
            }
            else if((a & m)==0 && (b&m)==0){
              if(carry==1){
                  num= num | m;
                  carry=0;
              }
            }
          cout<<num<<endl;
        }
      return num;
    }
};