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
#include<cmath>
#include<algorithm>
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){
         return 0;
        }
        if(root->left==NULL && root->right==NULL){
          return 1;
        }
        
        if(root->left==NULL && root->right!=NULL){
          return minDepth(root->right)+1; 
        }        
        if(root->left!=NULL && root->right==NULL){
            return minDepth(root->left)+1;
        }
        else{
          int leftAns=minDepth(root->left);
          int rightAns=minDepth(root->right);
          int min_ans=min(leftAns,rightAns)+1;
          return min_ans;     
        }
       
    }
};