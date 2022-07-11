// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
   Node * rev(Node * head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node * secondHead=rev(head->next);
        head->next->next=head;
        head->next=NULL;
        return secondHead;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node * revhead=rev(head);
        int carry=1;
        Node * temp=revhead;
        Node * prev=NULL;
        while(temp!=NULL || carry!=0){
            if(temp!=NULL){
               int data=temp->data+carry;
               temp->data=data%10;
               carry=data/10;
               prev=temp;
               temp=temp->next;
            }
            else if(carry!=0){
                int data=carry;
                Node * newNode=new Node(data%10);
                carry=data/10;
                prev->next=newNode;
                prev=newNode;
            }
        }
        
        return rev(revhead);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends