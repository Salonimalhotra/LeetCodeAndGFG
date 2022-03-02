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
class Pair{
  public:
  int height;
  int diamter;
};
class Solution {
public:
    Pair helper(TreeNode *root){
        if(root==NULL){
            Pair ans;
            ans.height=0;
            ans.diamter=0;
            return ans;
        }
        
        Pair LeftAns=helper(root->left);
        Pair RightAns=helper(root->right);
        Pair finalAns;
        finalAns.diamter=max(max(LeftAns.diamter,RightAns.diamter),LeftAns.height+RightAns.height);
 finalAns.height=1+max(LeftAns.height,RightAns.height);
        return finalAns;
        
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        Pair ans=helper(root);
        return ans.diamter; 
    }
};