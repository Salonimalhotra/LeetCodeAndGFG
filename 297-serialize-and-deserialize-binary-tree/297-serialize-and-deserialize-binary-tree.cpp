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
        if(root==NULL){
            return "";
        }
        
        queue<TreeNode *>q;
        q.push(root);
        string ans="";
        while(q.size()!=0){
            TreeNode * topNode=q.front();
            q.pop();
            if(topNode==NULL){
                ans.append("#,");
                
            }
            else{
                ans.append(to_string(topNode->val) + ',');
                q.push(topNode->left);
                q.push(topNode->right);
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
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));