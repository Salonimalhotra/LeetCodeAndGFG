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
    TreeNode * helper(vector<int>&preorder,int &start,int end,int maxi,int mini){
        if(start>end){
            return NULL;
        }
      
        if(preorder[start]>mini && preorder[start]<maxi){
            TreeNode * newNode=new TreeNode(preorder[start]);
            start++;
            newNode->left=helper(preorder,start,end,newNode->val,mini);
            newNode->right=helper(preorder,start,end,maxi,newNode->val);
            return newNode;
        }
        
         return NULL;
           
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
          int start=0;
          return helper(preorder,start,preorder.size()-1,INT_MAX,INT_MIN);
    }
};