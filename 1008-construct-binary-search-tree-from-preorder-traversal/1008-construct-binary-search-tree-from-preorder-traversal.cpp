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
    TreeNode* bstFromPreorderHelper(vector<int>&preorder,int start,int end)
    {
        if(start>end){
         return NULL; 
         }
        TreeNode * root=new TreeNode(preorder[start]);
        bool check=false;
        int i=start+1;
        while(i<=end){
         if(preorder[i]>root->val){
             check=true;
             break;
         }
            i++;
        }
        int leftEnd;
        if(check==true){
            leftEnd=i-1;
        }
        else if(check==false){
            leftEnd=end;
        }
        
        TreeNode* leftSubTree=bstFromPreorderHelper(preorder,start+1,leftEnd);
        TreeNode* rightSubTree=bstFromPreorderHelper(preorder,leftEnd+1,end);
        root->left=leftSubTree;
        root->right=rightSubTree;
        return root;       
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode * ans=bstFromPreorderHelper(preorder,0,preorder.size()-1);
         return ans;
    }
};