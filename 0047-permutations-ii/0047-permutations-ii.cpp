class Solution {
public:
     int permuteHelper(vector<int>&nums,vector<vector<int>>&output){
        if(nums.size()==0){
            vector<int>ans;
            output.push_back(ans);
            return 1;
        }
       
        int k=0;
    for(int i=0;i<nums.size();i++){
             vector<vector<int>>output1;
             vector<int>smallInput;
         for(int j=0;j<nums.size();j++){
             if(j!=i){
                  smallInput.push_back(nums[j]);        
            }
         }   
         int smallAns=permuteHelper(smallInput,output1);
          for(int m=0;m<smallAns;m++){
            vector<int>ans;
            ans.push_back(nums[i]);
            for(int n=0;n<output1[m].size();n++){
             ans.push_back(output1[m][n]);
             }
            output.push_back(ans); 
             k++;
            }
       
      }
        return k;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>output;
        int k=permuteHelper(nums,output);
        set<vector<int>>ans;
        for(int i=0;i<k;i++){
          ans.insert(output[i]);
        }
        vector<vector<int>>finalans;
        for(auto i:ans){
          finalans.push_back(i);
        }
        return finalans;
    }
};