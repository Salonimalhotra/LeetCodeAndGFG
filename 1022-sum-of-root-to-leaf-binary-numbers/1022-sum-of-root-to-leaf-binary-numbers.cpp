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
    void helper(TreeNode * root,int num,int &sum){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            int x=num * 2 + root->val;
            sum+=x;
            return;
        }
        
        helper(root->left,num * 2 + root->val,sum);
        helper(root->right,num * 2 + root->val,sum);
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL){
            return 0;
        }        
        int num=0;
        int sum=0;
        helper(root,num,sum);
        return sum;
        
    }
};