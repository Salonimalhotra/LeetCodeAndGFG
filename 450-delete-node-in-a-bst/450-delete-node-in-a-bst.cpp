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
    bool search(TreeNode*root,int key){
        if(root==NULL){
         return false;
        }
        if(root->val==key){
            return true;
        }
        return search(root->left,key) || search(root->right,key);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
       
        if(root==NULL){
            return root;
        }
    
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
            return root;
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
            return root;
        }
        else if(root->val==key){
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left==NULL && root->right!=NULL){
              TreeNode * temp=root->right;
                root->right=NULL;
                delete root;
                return temp;
            }
            else if(root->left!=NULL && root->right==NULL){
              TreeNode * temp=root->left;
                root->left=NULL;
                delete root;
                return temp;
            }
            else{
                TreeNode * temp=root->right;
                while(temp->left!=NULL){
                 temp=temp->left;  
                }
                int min_data=temp->val;
                root->val=min_data;
                root->right=deleteNode(root->right,min_data);
                return root;
            }
        }
        return root;
    }
};