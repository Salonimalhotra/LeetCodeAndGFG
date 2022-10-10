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
    int helper(TreeNode * root,int &sum){
      if(root==NULL){
         return 1;
      }
      
      int leftans=helper(root->left,sum);
      int rightans=helper(root->right,sum);
      
      if(leftans==0 || rightans==0){
         sum++;
         return 2;
      }
      
      else if(leftans==1 && rightans==1){
         return 0;
      }
      
      else if(leftans==2 || rightans==2){
         // ournode is monitored;
          return 1;
      }
      return 1;
    }
    int minCameraCover(TreeNode* root) {
        int sum=0;
        int ans=helper(root,sum);
        if(ans==0) sum++;
        return sum;
    }
};