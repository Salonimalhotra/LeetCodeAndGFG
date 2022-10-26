/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int helper(TreeNode *root,int &ans)
        {
            if (root == NULL) return 0;
            int leftans = helper(root->left,ans);
            int rightans = helper(root->right,ans);
            ans+=abs(leftans) + abs(rightans);
            return leftans + rightans + root->val -1;
        }
    int distributeCoins(TreeNode *root)
    {
       int ans=0;
       int smallans=helper(root,ans);
       return ans;
    }
};