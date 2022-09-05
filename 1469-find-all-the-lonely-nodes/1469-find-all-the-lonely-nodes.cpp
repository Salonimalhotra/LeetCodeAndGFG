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
    void solve(TreeNode * root,vector<int>&helper){
        if(root==NULL){
            return;
        }
        else if(root->left==NULL && root->right==NULL){
            return;
        }
        else if(root->left==NULL && root->right!=NULL){
            helper.push_back(root->right->val);
            solve(root->right,helper);
        }
        else if(root->left!=NULL && root->right==NULL){
             helper.push_back(root->left->val);
             solve(root->left,helper);
        }
        else if(root->left!=NULL && root->right!=NULL){
               solve(root->left,helper);
               solve(root->right,helper);
        }
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int>helper;
        solve(root,helper);
        return helper;
    }
};