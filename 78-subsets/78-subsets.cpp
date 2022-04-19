class Solution {
public:
    int subsetsHelper(vector<int>nums,vector<vector<int>>&output){
        if(nums.size()==0){
            vector<int>ans;
            output.push_back(ans);
            return 1;
        }
        
        vector<int>smallInput;
        for(int i=1;i<nums.size();i++){
            smallInput.push_back(nums[i]);
        }
        int smallAnsSize=subsetsHelper(smallInput,output);
        for(int i=0;i<smallAnsSize;i++){
            vector<int>ans1;
            ans1.push_back(nums[0]);
            for(int j=0;j<output[i].size();j++){
                ans1.push_back(output[i][j]);
            }
            output.push_back(ans1);
        }
        
        return 2*smallAnsSize;
       
    }
     void removeDuplicateSubsets(vector<vector<int>>&output){
        for(auto i=output.begin();i!=output.end();i++){
            bool check=false;
            for(auto j=i+1;j!=output.end();j++){
                if(i==j){
                    check=true;
                }
            }
            if(check==true){
                output.erase(i);
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>output;
        int finalSize=subsetsHelper(nums,output);
        removeDuplicateSubsets(output);
        return output;
        
    }
};