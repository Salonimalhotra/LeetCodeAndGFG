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
    int height(TreeNode * root){
        if(root==NULL){
           return 0;
        }
        return max(height(root->left),height(root->right)) + 1;
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth=height(root)-1;
        // cout<<maxDepth<<endl;
        int lvl=0;
        queue<TreeNode * >q;
        q.push(root);
        while(q.size()!=0){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode * topNode=q.front();
                q.pop();
                if(lvl==maxDepth && i==0){
                    return topNode->val; 
                }
                
                if(topNode->left!=NULL){
                    q.push(topNode->left);
                }
                 if(topNode->right!=NULL){
                    q.push(topNode->right);
                }
            }
            lvl++;
        }
        return -1;
    }
};