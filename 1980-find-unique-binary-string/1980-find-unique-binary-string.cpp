class Solution
{
    public:
        void helper(string x, int len_desired, unordered_map<string, int> &mp, string &ans) {
          if(x.size()==len_desired){
            if(mp.find(x)==mp.end()){
               ans=x;
             
            }
             return;            
          }          
        
          helper(x + '0',len_desired,mp,ans);
          helper(x + '1',len_desired,mp,ans);
          return;
        }
    string findDifferentBinaryString(vector<string> &nums)
    {
        unordered_map<string, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        string ans= "";
        string x="";
        helper(x,nums[0].size(),mp,ans);
        return ans;
    }
};