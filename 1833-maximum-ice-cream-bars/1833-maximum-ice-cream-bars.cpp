class Solution {
public:
//     int tabulation(vector<int>& costs, int coins){
//         vector<int>prev(coins+1,0);
//         vector<int>curr(coins+1,0);        

//         for(int i=1;i<=costs.size();i++){
//             for(int j=1;j<=coins;j++){
//                 if(costs[i-1]<=j){
//                     curr[j]=max(1 + prev[j-costs[i-1]],curr[j]);
//                 }
//                 else{
//                         curr[j]=prev[j];
//                 }
//             }
//             prev=curr;
//         }
//         return prev[coins];
//     }
    int maxIceCream(vector<int>& costs, int coins) {
        // return tabulation(costs,coins);   
        sort(costs.begin(),costs.end());
        int cnt=0;
        int i=0;
        while(coins>=0 && i<costs.size()){
            if(costs[i]<=coins){
                coins-=costs[i];
                i++;
                cnt++;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};