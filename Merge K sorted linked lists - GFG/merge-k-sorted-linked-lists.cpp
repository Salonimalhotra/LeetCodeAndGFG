// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * merge(Node * l1,Node * l2){
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        else if(l1==NULL){
            return l2;
        }
        else if(l2==NULL){
            return l1;
        }
        else{
            Node * temp1=l1;
            Node * temp2=l2;
            Node * newhead=NULL;
            Node * newtail=NULL;
            
            while(temp1!=NULL && temp2!=NULL){
                 if(temp1->data<=temp2->data){
                     if(newhead==NULL){
                         newhead=temp1;
                         newtail=temp1;
                     }
                     else{
                         newtail->next=temp1;
                         newtail=temp1;
                     }
                      temp1=temp1->next;
                 }
                 else{
                      if(newhead==NULL){
                         newhead=temp2;
                         newtail=temp2;
                     }
                     else{
                         newtail->next=temp2;
                         newtail=temp2;
                     }
                      temp2=temp2->next;
                 }
            }
            
            while(temp1!=NULL){
                newtail->next=temp1;
                newtail=temp1;
                temp1=temp1->next;
            }
            
            while(temp2!=NULL){
                 newtail->next=temp2;
                 newtail=temp2;
                 temp2=temp2->next;
            }
            
             return newhead;
        }
       
    }
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           if(K==0){
               return NULL;
           }
           else if(K==1){
               return arr[0];
           }
           Node * mergeFinalHead=merge(arr[0],arr[1]);
           for(int i=2;i<K;i++){
               mergeFinalHead=merge(mergeFinalHead,arr[i]);
           }
           
           return mergeFinalHead;
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends