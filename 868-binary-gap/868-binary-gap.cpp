class Solution {
public:
    int binaryGap(int n) {
        int maxgap=0;
        int last=-1;
        for(int i=0;i<32;i++){
            int m=1<<i;
            if((n & m)!=0){
                if(last==-1){
                    last=i+1;
                } 
                else{ 
                    maxgap=max(maxgap,(i+1-last));
                    last=i+1;
                    }
            }
            
        }
        return maxgap;
    }
};