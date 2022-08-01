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
    TreeNode * helper(vector<int>&preorder,vector<int>&inorder,int preS,int preE,int inS,int inE){
        if(preS>preE){
            return NULL;
        }
        
        int preorderRootIndex=preS;
        int rootdata=preorder[preS];
        TreeNode * root=new TreeNode(rootdata);
        
        int inorderRootIndex=-1;
        for(int i=inS;i<=inE;i++){
            if(inorder[i]==rootdata){
                inorderRootIndex=i;
                break;
            }
        }
        
        int lpreS=preorderRootIndex+1;
        int linS=inS;
        int linE=inorderRootIndex-1;
        int lpreE=linE-linS+lpreS;
        
        
        int rpreS=lpreE+1;
        int rpreE=preE;
        int rinS=inorderRootIndex+1;
        int rinE=inE;
        
        root->left=helper(preorder,inorder,lpreS,lpreE,linS,linE);
        root->right=helper(preorder,inorder,rpreS,rpreE,rinS,rinE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preS=0;
        int preE=preorder.size()-1;
        int inS=0;
        int inE=inorder.size()-1;
        return helper(preorder,inorder,preS,preE,inS,inE);
        
    }
};