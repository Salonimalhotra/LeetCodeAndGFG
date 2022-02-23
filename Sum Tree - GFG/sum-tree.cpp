// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class check{
    public:
  bool isSumTreeCheck;
  int SumTree;
};
class Solution
{
    public:
    int Sum(Node *root){
        if(root==NULL){
            return 0;
        }
        else return root->data+Sum(root->left)+Sum(root->right);
    }
    check Helper(Node*root){
        if(root==NULL){
            check ans;
            ans.isSumTreeCheck=true;
            ans.SumTree=0;
            return ans;
        }
        if(root->left==NULL && root->right==NULL){
            check ans;
            ans.isSumTreeCheck=true;
            ans.SumTree=root->data;
            return ans;
        }
        
        check lans=Helper(root->left);
        check rans=Helper(root->right);
        if(lans.isSumTreeCheck==true && rans.isSumTreeCheck==true){
            if(root->data==lans.SumTree+rans.SumTree){
                check final_ans;
                final_ans.isSumTreeCheck=true;
                final_ans.SumTree=Sum(root);
                return final_ans;
            }
            else{
                 check final_ans;
                final_ans.isSumTreeCheck=false;
                final_ans.SumTree=Sum(root);
                return final_ans;
            }
        }
        else{
                check final_ans;
                final_ans.isSumTreeCheck=false;
                final_ans.SumTree=Sum(root);
                return final_ans;
        }
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         check ans=Helper(root);
         return ans.isSumTreeCheck;
         
    }
};

// { Driver Code Starts.

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout <<ob.isSumTree(root) << endl;
    }
    return 1;
}  // } Driver Code Ends