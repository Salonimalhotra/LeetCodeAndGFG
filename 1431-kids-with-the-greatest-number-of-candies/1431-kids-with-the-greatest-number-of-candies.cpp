#include<vector>
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>v(candies.size(),extraCandies);
        int n=candies.size();
        for(int i=0;i<n;i++){
            int x=candies[i]+extraCandies;
            bool ans=true;
            for(int j=0;j<n;j++){
                if(j==i){
                    continue;
                }
                else{
                    if(candies[j]>x){
                        ans=false;
                        break;
                    }
                }
            }
            v[i]=ans;            
        }
        
        return v;
    }
    
};