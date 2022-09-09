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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *>q;
        bool flag=true;
        q.push(root);
        while(q.size()!=0){
            TreeNode * topNode=q.front();
            q.pop();
            if(topNode==NULL){
                flag=false;
            }
            else{
                if(flag==false){
                    return false;
                }            
            q.push(topNode->left);
            q.push(topNode->right);
             }
        }
        return true;
    }
};