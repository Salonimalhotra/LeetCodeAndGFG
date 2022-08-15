class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>nums;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C"){
                nums.pop_back();
            }
            else if(ops[i]=="D"){
                 int n=nums.size();
                nums.push_back(nums[n-1] * 2);
            }
            else if(ops[i]=="+"){
                int n=nums.size();
                nums.push_back(nums[n-1] + nums[n-2]);
            }
            else{
                 int z=stoi(ops[i]);
                 nums.push_back(z);
            }
        }
        
        int finalAns=0;
        for(int i=0;i<nums.size();i++){
            finalAns+=nums[i];
        }
        return finalAns;
    }
};