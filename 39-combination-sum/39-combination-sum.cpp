class Solution {
public:
    void helper(vector<int>&candidates,vector<int>&output,vector<vector<int>>&ans,int target,int index){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(output);
            }
            return;
        }
        if(candidates[index]<=target){
            output.push_back(candidates[index]);
            helper(candidates,output,ans,target-candidates[index],index);
            output.pop_back();
        }
        helper(candidates,output,ans,target,index+1);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>output;
        helper(candidates,output,ans,target,0);
        return ans;
    }
};