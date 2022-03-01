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
#include<vector>
#include<queue>
class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        vector<int>smallAns;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while(q.size()!=0){
            TreeNode * frontNode=q.front();
            q.pop();
            if(frontNode==NULL){
                if(q.size()==0){
                    ans.push_back(smallAns);
                    return ans;
                }
                ans.push_back(smallAns);
                smallAns.clear();       
                q.push(NULL);
            }
            else{
                 smallAns.push_back(frontNode->val);
                if(frontNode->left!=NULL){
                    q.push(frontNode->left);
                }
                if(frontNode->right!=NULL){
                    q.push(frontNode->right);
                }
                                
            }      
            
        }
        return ans;
    }
};