class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n=rowIndex+1;
        vector<vector<int>>ans;
        vector<int>ans1(1,1);
        ans.push_back(ans1);
        for(int i=1;i<=rowIndex;i++){
            vector<int>arr;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    arr.push_back(1);
                }
                else{
                    arr.push_back(ans[i-1][j] + ans[i-1][j-1]);
                }
            }
            ans.push_back(arr);
            if(i==rowIndex){
                return arr;
            }
        }
        return ans1;
    }
};