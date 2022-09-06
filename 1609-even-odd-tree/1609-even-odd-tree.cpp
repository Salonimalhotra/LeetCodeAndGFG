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
    bool isEvenOddTree(TreeNode* root) {
          queue<TreeNode *>q;
          q.push(root);
        int level=0;
        while(q.size()!=0){
            int s=q.size();
            int lastElement=-1;
            for(int i=0;i<s;i++){
                TreeNode * topNode=q.front();
                q.pop();
                if(level%2==0){
                    if(topNode->val%2==0){
                        return false;
                    }
                }
                
                if(level%2!=0){
                    if(topNode->val%2!=0){
                        return false;
                    }
                }
                
                if(lastElement==-1){
                    lastElement=topNode->val;
                }
                else if(level%2!=0 && topNode->val>=lastElement){
                        return false;                       
                    }
                    
                 else if(level%2==0 && topNode->val<=lastElement){
                        return false;                       
                   }
                
                lastElement=topNode->val;
                
                if(topNode->left!=NULL){
                    q.push(topNode->left);
                }
                if(topNode->right!=NULL){
                    q.push(topNode->right);
                }
                
            }
            level++;
        }
        return true;
    }
};