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
    pair<int,pair<TreeNode*,bool>> helper(TreeNode * root,TreeNode * parent,int depth,int x){
        if(root==NULL){
             pair<int,pair<TreeNode*,bool>>ans;
             ans.first=depth;
             ans.second.first=parent;
             ans.second.second=false;
            return ans;
        }
        
         if(root->val==x){
              pair<int,pair<TreeNode*,bool>>ans;
              ans.first=depth;
             ans.second.first=parent;
             ans.second.second=true;
             return ans;              
         }
        
            pair<int,pair<TreeNode*,bool>>leftAns=helper(root->left,root,depth+1,x);
           if(leftAns.second.second==true){
               return leftAns;
           }
        else{
            return helper(root->right,root,depth+1,x);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
           
             pair<int,pair<TreeNode*,bool>>xAns=helper(root,NULL,1,x);
             pair<int,pair<TreeNode*,bool>>yAns=helper(root,NULL,1,y);
             
             if(xAns.second.second==true && yAns.second.second==true && xAns.second.first!=yAns.second.first && xAns.first==yAns.first){
                 return true;
             }
        else{
            return false;
        }
    }
};