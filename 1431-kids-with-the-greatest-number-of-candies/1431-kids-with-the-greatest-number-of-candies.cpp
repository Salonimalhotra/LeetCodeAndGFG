#include<climits>
#include<vector>
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>v(candies.size(),false);
        int maxCandies=INT_MIN;
        for(int i=0;i<candies.size();i++){
            if(candies[i]>maxCandies){
                maxCandies=candies[i];
            }
        }
        
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=maxCandies){
                v[i]=true;
            }
            else{
                v[i]=false;
            }
        }
        return v;
    }
    
};