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
    void helper(TreeNode * root,TreeNode * parent,TreeNode * grandparent,int &sum){
        if(root==NULL){
            return;
        }
        
        if(grandparent!=NULL && grandparent->val%2==0){
            sum+=root->val;
        }
        
        helper(root->left,root,parent,sum);
        helper(root->right,root,parent,sum);
        return;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        helper(root,NULL,NULL,sum);
        return sum;
    }
};