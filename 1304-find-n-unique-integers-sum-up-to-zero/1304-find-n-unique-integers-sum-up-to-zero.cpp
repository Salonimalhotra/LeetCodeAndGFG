class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n%2==0){
            for(int i=-1;i>=-1 * (n/2);i--){
                ans.push_back(i);
            }
            for(int i=1;i<=n/2;i++){
                ans.push_back(i);
            }
        }
        
        else if(n%2!=0){
            int x=(n-1)/2;
            for(int i=-1 *x;i<=-1;i++){
                ans.push_back(i);
            }
            ans.push_back(0);
            for(int i=1;i<=x;i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};