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
    TreeNode * helper(vector<int>&preorder,int start,int end){
        if(start>end){
            return NULL;
        }
        int rootData=preorder[start];
        TreeNode * root=new TreeNode(rootData);
        int i=start+1;
        while(i<=preorder.size()-1 && preorder[i]<rootData){
            i++;
        }
        root->left=helper(preorder,start+1,i-1);
        root->right=helper(preorder,i,end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int start=0;
        int end=preorder.size()-1;
        TreeNode * root=helper(preorder,start,end);
        return root;
        
    }
};