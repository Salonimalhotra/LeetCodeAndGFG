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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode *>q;
        q.push(root);
        while(q.size()!=0){
            int maxElement=INT_MIN;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode * topNode=q.front();
                q.pop();
                if(topNode->left!=NULL){
                    q.push(topNode->left);
                }
                if(topNode->right!=NULL){
                    q.push(topNode->right);
                }
                maxElement=max(maxElement,topNode->val);
            }
            ans.push_back(maxElement);
        }
        return ans;
    }
};