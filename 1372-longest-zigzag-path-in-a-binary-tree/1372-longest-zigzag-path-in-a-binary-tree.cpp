/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
       	//     void helper(TreeNode *root,int &maxVal,int val,bool left){
       	//       if(root==NULL) return;     
       	//       maxVal=max(maxVal,val);
       	//       if(left==true){
       	//          helper(root->right,maxVal,val+1,false);
       	//          helper(root->right,maxVal,0,true);
       	//          helper(root->left,maxVal,0,true);

       	//       }
       	//       else{
       	//          helper(root->left,maxVal,val+1,true);
       	//          helper(root->left,maxVal,0,false);
       	//          helper(root->right,maxVal,0,false);         
       	//       }
       	//     }
        pair<int, int> helper(TreeNode *root, int &maxAns)
        {
            if (root == NULL)
            {
                pair<int, int> ans;
                ans.first = 0;
                ans.second = 0;
                return ans;
            }

            pair<int, int> leftAns = helper(root->left, maxAns);
            pair<int, int> rightAns = helper(root->right, maxAns);
            maxAns = max(maxAns, max(leftAns.second + 1, max(rightAns.first + 1, max(leftAns.first, rightAns.second))));
            pair<int, int> finalans;
            finalans.first = leftAns.second + 1;
            finalans.second = rightAns.first + 1;
            return finalans;
        }

    int longestZigZag(TreeNode *root)
    {
        int maxAns = 0;
        pair<int, int> ans = helper(root, maxAns);
        return maxAns-1;
    }
};