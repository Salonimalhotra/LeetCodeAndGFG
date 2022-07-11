// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node * reverse(Node * head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node * sec=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return sec;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        // Node * head1=first;
        // Node * head2=second;
         if(first==NULL || second==NULL){
            return NULL;
        }
        
        Node * firstreverse_head=reverse(first);
        Node * secondreverse_head=reverse(second);
        int sum=0;
        int carry=0;
        Node * temp1=firstreverse_head;
        Node * temp2=secondreverse_head;
        Node * newhead=NULL;
        Node *newtail=NULL;
        
        while(carry!=0  || temp1!=NULL || temp2!=NULL){
            if(temp1!=NULL && temp2!=NULL){
                sum+=temp1->data+temp2->data;
                temp1=temp1->next;
                temp2=temp2->next;
                
            }
            
            else if(temp1!=NULL){
                sum+=temp1->data;
                 temp1=temp1->next;
            }
            
            else if(temp2!=NULL){
                sum+=temp2->data;
                 temp2=temp2->next;
            }
            
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            
           if(sum>=0){
               Node * newnode=new Node(sum);
               if(newhead==NULL){
                   newhead=newnode;
                   newtail=newnode;
                   
               }
               
               else{
                   newtail->next=newnode;
                   newtail=newnode;
                   
               }
           }
           sum=0;
            
        }
        newtail->next=NULL;
        return reverse(newhead);
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends