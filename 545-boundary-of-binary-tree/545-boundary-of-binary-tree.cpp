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
    void leftBoundary(TreeNode * root,vector<int>&ans){
        TreeNode * temp=root->left;
        while(temp!=NULL){
            if(temp->left==NULL && temp->right==NULL){
                break;
            }
            ans.push_back(temp->val);
            if(temp->left!=NULL){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        return;
    }
    
   void leafNodes(TreeNode * root,vector<int>&ans){
       if(root==NULL){
           return;
       }
       if(root->left==NULL && root->right==NULL){
           ans.push_back(root->val);
           return;
       }
       
       leafNodes(root->left,ans);
       leafNodes(root->right,ans);
       return;
   }
      void rightBoundary(TreeNode * root,vector<int>&ans){
            TreeNode * temp=root->right;
        while(temp!=NULL){
            if(temp->left==NULL && temp->right==NULL){
                break;
            }
            ans.push_back(temp->val);
            if(temp->right!=NULL){
                temp=temp->right;
            }
            else{
                temp=temp->left;
            }
        }
        return;
       
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        else if(root->left==NULL && root->right==NULL){
            ans.push_back(root->val);
            return ans;
        }
        ans.push_back(root->val);
        leftBoundary(root,ans);
        leafNodes(root,ans);
        vector<int>ans1;        
        rightBoundary(root,ans1);
        reverse(ans1.begin(),ans1.end());
        // rightBoundary(root,ans);   
        for(int i=0;i<ans1.size();i++){
            ans.push_back(ans1[i]);
        }
        return ans;
        
    }
};