/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(root==NULL)return ans;
        queue<TreeNode *>q;
        q.push(root);
        while(q.size()!=0){
            TreeNode * topElement=q.front();
            q.pop();
           if(topElement==NULL){
              ans.append("#,");
           }            
           else{
               ans.append(to_string(topElement->val) + ",");
               q.push(topElement->left);
               q.push(topElement->right);
           }            
        }
        
        return ans;
    }

    // Decodes your encoded data to tree.
    
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode * root=new TreeNode(stoi(str));
        queue<TreeNode *>q;
        q.push(root);
        while(q.size()!=0){
            TreeNode * currNode=q.front();
            q.pop();
            
            getline(s,str,',');
            if(str=="#"){
                currNode->left=NULL;
            }
            else{
                TreeNode * leftNode=new TreeNode(stoi(str));
                currNode->left=leftNode;
                q.push(leftNode);
            }
            
            getline(s,str,',');
            if(str=="#"){
                currNode->right=NULL;
            }
            else{
                TreeNode * rightNode=new TreeNode(stoi(str));
                currNode->right=rightNode;
                q.push(rightNode);
            }
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;