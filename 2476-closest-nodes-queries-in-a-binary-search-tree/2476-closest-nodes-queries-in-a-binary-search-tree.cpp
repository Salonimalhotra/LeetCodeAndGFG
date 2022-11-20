/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
       	//         int getSmallest(TreeNode *root, int xi)
       	//         {
       	//             if (root == NULL) return -1;

       	//             int ans = -1;
       	//             if (root->val == xi) return root->val;

       	//             else if (root->val > xi) return getSmallest(root->left, xi);

       	//             else
       	//             {
       	//                 int leftoverans = getSmallest(root->right, xi);
       	//                 if (leftoverans == -1) ans = root->val;
       	//                 else ans = leftoverans;
       	//             }
       	//             return ans;
       	//         }

       	//     int getLargest(TreeNode *root, int xi)
       	//     {
       	//         if (root == NULL) return -1;

       	//         int ans = -1;
       	//         if (root->val == xi) return root->val;

       	//         else if (root->val < xi) return getLargest(root->right, xi);

       	//         else
       	//         {
       	//             int leftoverans = getLargest(root->left, xi);
       	//             if (leftoverans == -1) ans = root->val;

       	//             else ans = leftoverans;
       	//         }
       	//       return ans;
       	//     }
        void helper(TreeNode *root, vector<int> &inorder)
        {
            if (root == NULL)
            {
                return;
            }

            helper(root->left, inorder);
            inorder.push_back(root->val);
            helper(root->right, inorder);
        }
    int getLow(vector<int> &inorder, int xi)
    {
        int ans = -1;
        int start = 0;
        int end = inorder.size() - 1;

        while (start <= end)
        {
            int mid = (start + (end - start) / 2);
            if (inorder[mid] == xi)
            {
                return inorder[mid];
            }
            else if (inorder[mid] > xi)
            {
                end = mid - 1;
            }
            else if (inorder[mid] < xi)
            {
                ans = inorder[mid];
                start = mid + 1;
            }
        }
        return ans;
    }
    int getHigh(vector<int> &inorder, int xi)
    {
        int ans = -1;
        int start = 0;
        int end = inorder.size() - 1;

        while (start <= end)
        {
            int mid = (start + (end - start) / 2);
            if (inorder[mid] == xi)
            {
                return inorder[mid];
            }
            else if (inorder[mid] < xi)
            {
                start = mid + 1;
            }
            else if (inorder[mid] > xi)
            {
                ans = inorder[mid];
                end = mid - 1;
            }
        }
        return ans;
    }
    vector<vector < int>> closestNodes(TreeNode *root, vector<int> &queries)
    {
        vector<vector < int>> ans;
        vector<int> inorder;
        helper(root, inorder);
        for (int i = 0; i < queries.size(); i++)
        {
            vector<int> smallans;
            int minValue = getLow(inorder, queries[i]);
            int maxValue = getHigh(inorder, queries[i]);
            smallans.push_back(minValue);
            smallans.push_back(maxValue);
            ans.push_back(smallans);
        }
        return ans;
    }
};