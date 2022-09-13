/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string helper(TreeNode * root,unordered_map<string,int>&mp, vector<TreeNode*>&ans){
    if(root==NULL){
        return "";
    }
    
    if(root->left==NULL && root->right==NULL){
        string x=to_string(root->val);
        if(mp.find(x)!=mp.end() && mp[x]==1){
            ans.push_back(root);
            mp[x]++;  
        }
        else{
            mp[x]++;      
        }
        return x;
    }
    string finalAns=to_string(root->val);
    finalAns.push_back(' ');
    string leftAns=helper(root->left,mp,ans);
    string rightAns=helper(root->right,mp,ans);
    finalAns.append(leftAns);
    finalAns.push_back(' ');
    finalAns.append(rightAns);
   
   
    if(mp.find(finalAns)!=mp.end() && mp[finalAns]==1){
           ans.push_back(root);
           mp[finalAns]++;  
    }
    else{
         mp[finalAns]++; 
    }
    return  finalAns;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>mp;
       vector<TreeNode *>ans;
       string smallAns=helper(root,mp,ans);
    //      for(auto i:mp){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
        return ans;
    }
};