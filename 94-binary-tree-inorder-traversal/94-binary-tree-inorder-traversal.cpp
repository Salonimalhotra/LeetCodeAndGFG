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
#include<stack>
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*>stack;
        TreeNode *s=root;
        while(stack.size()!=0 || s!=NULL){
            while(s!=NULL){
                stack.push(s);
                s=s->left;
            }
            if(s==NULL && stack.size()!=0){
                TreeNode * x=stack.top();
                stack.pop();
                ans.push_back(x->val);
                if(x->right!=NULL){
                    s=x->right;
                }
            }
        }
        return ans;
    }
};