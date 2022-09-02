class Solution {
public:
    int minSwaps(vector<int>& data) {
        int totalOnes=0;
        for(int i=0;i<data.size();i++){
            if(data[i]==1){
                totalOnes++;
            }
        }
        
        if(totalOnes==0){
            return 0;
        }
        
        int minSwaps=INT_MAX;
        int countZeroes=0;
        int i=0;
        int j=0;
        while(j<data.size()){
            if(data[j]==0){
                countZeroes++;
            }
            if(j-i+1<totalOnes){
                j++;
            }
            
            else if(j-i+1==totalOnes){
                 minSwaps=min(minSwaps,countZeroes);
                    if(data[i]==0){
                    countZeroes--;
                     }
                i++;
                j++;
            }
        }
        // if(minSwaps==INT_MAX){
        //     return 0;
        // }
        return minSwaps;
    }
};