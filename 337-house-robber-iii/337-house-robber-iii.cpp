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
    pair<int,int> helper(TreeNode * root){
        if(root==NULL){
               pair<int,int> ans;
               ans.first=0;
               ans.second=0;
               return ans;
        }
        
        if(root->left==NULL && root->right==NULL){
               pair<int,int> ans;
              ans.first=root->val;
              ans.second=0;
              return ans;            
        }
        
        
           pair<int,int>leftAns=helper(root->left);
           pair<int,int>rightAns=helper(root->right);
        
              pair<int,int> finalAns;
              int option1=max(leftAns.first,leftAns.second);
              int option2=max(rightAns.first,rightAns.second);
              finalAns.second=option1 + option2;
              finalAns.first=root->val + leftAns.second + rightAns.second;
              return finalAns;
    }
    int rob(TreeNode* root) {
            pair<int,int> ans=helper(root);
            return max(ans.first,ans.second);
    }
};