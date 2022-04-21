class Solution {
public:
    void solve(int index, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& x){
        if(index == candidates.size()){ // when we reach the end of the array
            if(target == 0){ // if our very own target has a specified combination to match it we push it into our final answer
                ans.push_back(x);
            }
            return;
        }
        
    if(candidates[index] <= target){ // if the current element is less than or equal to target, we push it into our data struct
        x.push_back(candidates[index]);
        solve(index, target - candidates[index], candidates, ans, x); // we then give a recursive call with a different target and the same index until we break either condition
        x.pop_back();
    }
    solve(index+1, target, candidates, ans, x); // if the condition breaks we move to the next index
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>x;
        solve(0, target, candidates, ans, x);
        return ans;
    }
};