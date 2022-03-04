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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        TreeNode * curr=root;
        stack<TreeNode*>stack;
        while(curr!=NULL || stack.size()!=0){
            if(curr!=NULL){
                stack.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode * temp=stack.top()->right;
                if(temp==NULL){
                    temp=stack.top();
                    stack.pop();
                    ans.push_back(temp->val);
                    while(stack.size()!=0 && temp==stack.top()->right){
                        temp=stack.top();
                        stack.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    curr=temp;
                }
            }
        }
        
        return ans;
    }
};