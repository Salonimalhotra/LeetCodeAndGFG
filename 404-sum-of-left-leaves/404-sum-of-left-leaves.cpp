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
    void sumOfLeftLeavesHelper(TreeNode * root,int &sum ,bool leaf){
        if(root==NULL){
            return; 
        }
        if(root->left==NULL && root->right==NULL && leaf==true){
            sum+=root->val;
            return;
        }
        
        if(root->left!=NULL){
            sumOfLeftLeavesHelper(root->left,sum,true);
            
        }
        
        if(root->right!=NULL){
            sumOfLeftLeavesHelper(root->right,sum,false);
        }
        return;        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        sumOfLeftLeavesHelper(root,sum,false);
        return sum;
    }
};