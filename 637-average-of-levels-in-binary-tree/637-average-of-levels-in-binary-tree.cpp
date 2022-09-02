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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0){
            double avg=0;
            int size=q.size();
            double sum=0;
            for(int i=0;i<size;i++){
                TreeNode * topNode=q.front();
                q.pop();
                sum+=topNode->val;
                if(topNode->left!=NULL){
                    q.push(topNode->left);
                }
                if(topNode->right!=NULL){
                    q.push(topNode->right);
                }
            }
            avg=sum/size;
            ans.push_back(avg);
        }
        return ans;
    }
};