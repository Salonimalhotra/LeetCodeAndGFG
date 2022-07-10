// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node * reverseLL(struct node * head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        node * newhead=reverseLL(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }
    int length(struct node * head){
        if(head==NULL){
            return 0;
        }
        else{
            return 1+length(head->next);
        }
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head==NULL){
            return head;
        }
        else if(head->next==NULL){
            return head;
        }
        else if(k==0){
            return head;
        }
        else if(k>=length(head)){
             return reverseLL(head);
        }
        node * curr=head;
        int count=0;
        while(curr!=NULL && count<k-1){
            curr=curr->next;
            count++;
        }
        node * temp=curr->next;
        curr->next=NULL;
        node * newhead=reverseLL(head);
        node * newtail=reverse(temp,k);
        head->next=newtail;
        return newhead;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends