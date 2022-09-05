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
class Helper{
    public:
    int Sum;
    int tilt;
};
class Solution {
public:
    Helper solve(TreeNode * root,int &sum){
        if(root==NULL){
            Helper ans;
            ans.Sum=0;
            ans.tilt=0;
            return ans;
        }
        
        Helper leftAns=solve(root->left,sum);
        Helper rightAns=solve(root->right,sum);
        Helper finalAns;
        finalAns.Sum=leftAns.Sum + rightAns.Sum + root->val;
        finalAns.tilt=abs(leftAns.Sum-rightAns.Sum);
        sum+=finalAns.tilt;
        return finalAns;        
    }
    int findTilt(TreeNode* root) {
        int sum=0;
        Helper h1=solve(root,sum);
        return sum;
    }
};