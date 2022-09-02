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
    int helper(TreeNode *root,int maxTillNow){
        if(root==NULL){
           return 0;
        }
        int ans=0;
        if(root->val>=maxTillNow){
            ans+=1;
        }
        
        ans+=helper(root->left,max(maxTillNow,root->val));
        ans+=helper(root->right,max(maxTillNow,root->val));
        return ans;        
    }
    int goodNodes(TreeNode* root) {
        return helper(root,INT_MIN);
    }
};