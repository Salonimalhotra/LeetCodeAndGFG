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
#include<queue>
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
         return 0;
        }   
        int sum=0;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0){
         TreeNode* top=q.front();
         q.pop();
            
        if(top->left!=NULL){
            if(top->left->left==NULL && top->left->right==NULL){
                     sum+=top->left->val;
            }
          
            q.push(top->left);
        }
            
        if(top->right!=NULL){
         q.push(top->right); 
        }            
        }
        return sum;
    }
};