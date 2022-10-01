class Solution {
public:
    int getSum(int a, int b) {
        int num=0;
        int carry=0;
        for(int i=0;i<32;i++){
             int m= 1<<i;
          // dealing when both bits of this number are 1 
          //then also we deal with 2 cases :- one is where we have an carry and second where there is no carry
             if((a & m)!=0 && (b&m)!=0){
               if(carry==0){
                    num= num & ~(m);
                    carry=1;    
               }
               else if(carry==1)num= num | m;                           
             }
          
            // dealing when only one of the  bits of this number are 1 
          //then also we deal with 2 cases :- one is where we have an carry and second where there is no carry
            else if((a & m)!=0 || (b&m)!=0){
              if(carry==0)num= num | m;
              else if(carry==1)num= num & ~(m);
            }
          
             // dealing when both of the  bits of this number are 0 
          //then also we deal with 2 cases :- one is where we have an carry and second where there is no carry
            else if((a & m)==0 && (b&m)==0){
              if(carry==1){
                  num= num | m;
                  carry=0;
              }
            }
          // cout<<num<<endl;
        }
      return num;
    }
};