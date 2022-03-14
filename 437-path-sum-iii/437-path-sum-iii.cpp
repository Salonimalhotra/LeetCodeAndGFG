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
    void Helper(TreeNode * root,int targetSum,int &count,vector<int>&ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        if(root->left!=NULL){
            Helper(root->left,targetSum,count,ans);
        }
        if(root->right!=NULL){
            Helper(root->right,targetSum,count,ans);
        }
        
        int x=0;
        for(int i=ans.size()-1;i>=0;i--){
            x+=ans[i];
            if(x==targetSum){
                count++;
            }
        }
        ans.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        vector<int>ans;
        Helper(root,targetSum,count,ans);
        return count;
    }
    
};