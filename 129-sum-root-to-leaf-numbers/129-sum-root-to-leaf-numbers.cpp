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
            int x=num * 10 + root->val;
            sum+=x;
            return;
        }
        
        if(root->left!=NULL){
            helper(root->left,num * 10 + root->val,sum);
        }
        
        if(root->right!=NULL){
            helper(root->right,num * 10 + root->val,sum);
        }
        return;
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int num=0;
        helper(root,num,sum);
        return sum;
        
    }
};