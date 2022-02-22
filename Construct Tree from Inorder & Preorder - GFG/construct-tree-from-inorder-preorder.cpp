// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node *buildTreeHelper(int *in,int *pre,int inS,int inE,int preS, int preE){
       
        if(inS>inE){
            return NULL;
        }
        int rootIndex_pre=preS;
        int rootData=pre[preS];
        int rootIndex_in;
        for(int i=inS;i<=inE;i++){
            if(in[i]==rootData){
                rootIndex_in=i;
                break;
            }
        }
        
        int LeftpreS=rootIndex_pre+1;
        int LeftinS=inS;
        int LeftinE=rootIndex_in-1;
        int LeftpreE=LeftinE-LeftinS+LeftpreS;
        
        int RightpreS=LeftpreE+1;
        int RightpreE=preE;
        int RightinS=rootIndex_in+1;
        int RightinE=inE;
        
        Node *root=new Node(rootData);
        root->left=buildTreeHelper(in,pre,LeftinS,LeftinE,LeftpreS,LeftpreE);
        root->right=buildTreeHelper(in,pre,RightinS,RightinE,RightpreS,RightpreE);
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        
        return buildTreeHelper(in,pre,0,n-1,0,n-1);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends