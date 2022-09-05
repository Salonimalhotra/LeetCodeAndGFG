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
    int maxLevelSum(TreeNode* root) {
        int maxAns=-1;
        int level=-1;
        int currlevel=0;
        queue<TreeNode *>q;
        q.push(root);
        
        while(q.size()!=0){
            int sum=0;
            currlevel++;
            int size=q.size();
            for(int i=0;i<size;i++){
              TreeNode * topNode=q.front();
              sum+=topNode->val;
              q.pop();  
              if(topNode->left!=NULL){
                  q.push(topNode->left);
              }
              if(topNode->right!=NULL){
                  q.push(topNode->right);
              }  
            }
            if(maxAns==-1){
                level=currlevel;
                maxAns=sum;
            }
            else if(maxAns<sum){
                level=currlevel;
                maxAns=sum;
            }
            
            
        }
        return level;
    }
};