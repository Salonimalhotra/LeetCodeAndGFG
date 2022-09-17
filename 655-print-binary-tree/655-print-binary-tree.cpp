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
        
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        
         return 1 + max(height(root->left),height(root->right));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h=height(root);
        h=h-1;
        int rows=h+1;;
        int cols=pow(2,h+1)-1;
        vector<vector<string>>ans(h+1,vector<string>(cols,""));
        ans[0][(cols-1)/2]=to_string(root->val);
        queue<pair<TreeNode *,pair<int,int>>>q;
        q.push(make_pair(root,make_pair(0,(cols-1)/2)));
        while(q.size()!=0){
            pair<TreeNode *,pair<int,int>> topElement=q.front();
            q.pop();
            int row=topElement.second.first;
            int col=topElement.second.second;
            
            if(topElement.first->left!=NULL){
                int leftrow=row + 1;
                int leftcol=col - pow(2,h-row-1);
                // cout<<topElement.first->left->val<<" ";
                ans[leftrow][leftcol]=to_string(topElement.first->left->val);
                q.push(make_pair(topElement.first->left,make_pair(leftrow,(leftcol))));               
            }
        
            if(topElement.first->right!=NULL){
                int rightrow=row + 1;
                int rightcol=col + pow(2,h-row-1);
                  // cout<<topElement.first->right->val<<" ";
                 ans[rightrow][rightcol]=to_string(topElement.first->right->val);
                 q.push(make_pair(topElement.first->right,make_pair(rightrow,(rightcol))));   
            }            
        }
        return ans;
    }
};