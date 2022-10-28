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
        void helper(TreeNode *root, vector<int> &def, int &index, vector<int> &voyage, bool &check)
        {
            if (root == NULL)
            {
                return;
            }
            if (root->val != voyage[index])
            {
               	// cout << "returning from here 1 " << root->val << endl;
                check = false;
                return;
            }

            if(root->left==NULL && root->right==NULL){
                   index++;      
            }        

            if (root->left != NULL && root->right != NULL)
            {

                if (voyage[index + 1] != root->left->val)
                {
                    TreeNode *extra = root->left;
                    root->left = root->right;
                    root->right = extra;
                    def.push_back(root->val);
                }
                index++;
                helper(root->left, def, index, voyage, check);
                helper(root->right, def, index, voyage, check);
            }
          
            else if (root->left != NULL)
            {
                if (voyage[index + 1] != root->left->val)
                {
                    check = false;
                    return;
                }
                index++;
                helper(root->left, def, index, voyage, check);
            }
            else if (root->right != NULL)
            {
                if (voyage[index + 1] != root->right->val)
                {
                    check = false;
                    return;
                }
                index++;
                helper(root->right, def, index, voyage, check);
            }
        }
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        vector<int> def;
        int index = 0;
        bool check = true;
        helper(root, def, index, voyage, check);
        if (check == false) return { -1 };
        return def;
    }
};