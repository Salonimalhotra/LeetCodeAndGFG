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
#include<vector>
class Solution {
public:
    void helper(TreeNode * root,int sum,vector<vector<int>>&ans,vector<int>&path){
        if(root==NULL){
           return;
        }
        else if(root->left==NULL && root->right==NULL && root->val==sum){
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();    
            return;
        }
        path.push_back(root->val);
        helper(root->left,sum-root->val,ans,path);
        helper(root->right,sum-root->val,ans,path);
        path.pop_back();
        return;        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>path;
        helper(root,targetSum,ans,path);
        return ans;        
    }
};