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
    void helper(TreeNode * root,vector<int>&x){
        if(root==NULL){
            return;
        }
        else if(root->left==NULL && root->right==NULL){
            x.push_back(root->val);
            return;
        }
        helper(root->left,x);
        helper(root->right,x);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>x1;
        vector<int>x2;
        helper(root1,x1);
        helper(root2,x2);
        bool ans=false;
        if(x1.size()!=x2.size()){
            return false;
        }
        for(int i=0;i<x1.size();i++){
            if(x1[i]!=x2[i]){
                return false;
            }
        }
        return true;
    }
};