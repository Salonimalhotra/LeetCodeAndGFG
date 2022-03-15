/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<vector>
class Solution {
public:
    void AllNodesAtDepthK(TreeNode * root,int k,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        AllNodesAtDepthK(root->left,k-1,ans);
        AllNodesAtDepthK(root->right,k-1,ans);
        return;
    }
    int Helper(TreeNode*root,TreeNode * target,int k,vector<int>&ans){
       if(root==NULL){
           return -1;
       }
        if(root->val==target->val){
            AllNodesAtDepthK(root,k,ans);
            return 0;
        }
        
        int leftAns=Helper(root->left,target,k,ans);
            if(leftAns!=-1){                       
              if(leftAns+1==k){
                  ans.push_back(root->val);               
               }
              else{
                  AllNodesAtDepthK(root->right,k-leftAns-2,ans);
                }
             return leftAns+1;
        }
        
        int rightAns=Helper(root->right,target,k,ans);
        if(rightAns!=-1){
           if(rightAns+1==k){
            ans.push_back(root->val);
            }
          else{
             AllNodesAtDepthK(root->left,k-rightAns-2,ans);
           }
         return rightAns+1;
        }
        
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
     vector<int>ans;
     if(root==NULL){
         return ans;
     }
     int x=Helper(root,target,k,ans);
     return ans;
    }
};