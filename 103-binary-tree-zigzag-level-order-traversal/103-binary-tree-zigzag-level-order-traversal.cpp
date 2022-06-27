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
#include<stack>
class Solution {
public:    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    // Write your code here
          vector<vector<int>>ans;
    if(root==NULL){
         return ans;
    }    
  
    stack<TreeNode*>right_to_left;
    stack<TreeNode*>left_to_right;
    right_to_left.push(root);
        vector<int>ans1;
    while(right_to_left.size()!=0 || left_to_right.size()!=0){
        while(right_to_left.size()!=0){
              TreeNode * frontNode=right_to_left.top();
              right_to_left.pop();
              // cout<<frontNode->data<<" ";
            ans1.push_back(frontNode->val);
              if(frontNode->left!=NULL){
                  left_to_right.push(frontNode->left);
              }
              if(frontNode->right!=NULL){
                  left_to_right.push(frontNode->right);
              }
        }
        ans.push_back(ans1);
        ans1.clear();
        if(left_to_right.size()!=0){
        while(left_to_right.size()!=0){
              TreeNode * frontNode=left_to_right.top();
              left_to_right.pop();
              // cout<<frontNode->data<<" ";
              ans1.push_back(frontNode->val);            
              if(frontNode->right!=NULL){
                  right_to_left.push(frontNode->right);
              }
              if(frontNode->left!=NULL){
                  right_to_left.push(frontNode->left);
              }
        }
         ans.push_back(ans1);
         ans1.clear();
        }
    } 
    return ans;    
  }
};