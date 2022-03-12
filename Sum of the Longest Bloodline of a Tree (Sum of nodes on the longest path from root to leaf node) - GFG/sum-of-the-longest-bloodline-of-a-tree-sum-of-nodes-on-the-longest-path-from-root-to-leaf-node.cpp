// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Special{
    public:
    int longestPath;
    int sumOfLongestpath;
};
class Solution
{
public:
    Special helper(Node * root){
        if(root==NULL){
         Special Ans;
         Ans.longestPath=0;
         Ans.sumOfLongestpath=0;
         return Ans;
        }
        
        if(root->left==NULL && root->right==NULL){
             Special Ans;
             Ans.longestPath=1;
            Ans.sumOfLongestpath=root->data;
             return Ans;
        }
        Special leftAns=helper(root->left);
        Special rightAns=helper(root->right);
        Special final_ans;
        
        if(leftAns.longestPath>rightAns.longestPath){
            final_ans.longestPath=leftAns.longestPath+1;
            final_ans.sumOfLongestpath=leftAns.sumOfLongestpath+root->data;
          
        }
        else if(leftAns.longestPath<rightAns.longestPath){
        
             final_ans.longestPath=rightAns.longestPath+1;
             final_ans.sumOfLongestpath=rightAns.sumOfLongestpath+root->data;
          
            
        }
        else{
            
             final_ans.longestPath=max(rightAns.longestPath,leftAns.longestPath)+1;
             final_ans.sumOfLongestpath= max(leftAns.sumOfLongestpath,rightAns.sumOfLongestpath)+root->data;
         }
        
          return final_ans;
          
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
       if(root==NULL){
           return 0;
       }
       
       Special final_ans=helper(root);
       return final_ans.sumOfLongestpath;
    }
    
};

// { Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}  // } Driver Code Ends