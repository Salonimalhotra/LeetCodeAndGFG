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
    Node * Helper(int in[],int pre[],int inS,int inE,int preS,int preE){
        if(preS>preE || inS>inE){
            return NULL;
        }
        int rootData=pre[preS];
        int inRootIndex;
        for(int i=inS;i<=inE;i++){
            if(in[i]==rootData){
                inRootIndex=i;
                break;
            }
        }
        
        Node * root=new Node(rootData);
        
        int LinS=inS;
        int LinE=inRootIndex-1;
        int LpreS=preS+1;
        int LpreE=LinE-LinS+LpreS;
        
        int RinS=inRootIndex+1;
        int RinE=inE;
        int RpreS=LpreE+1;
        int RpreE=preE;
        
        
        root->left=Helper(in,pre,LinS,LinE,LpreS,LpreE);
        root->right=Helper(in,pre,RinS,RinE,RpreS,RpreE);
        
        return root;
    }    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return Helper(in,pre,0,n-1,0,n-1);
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