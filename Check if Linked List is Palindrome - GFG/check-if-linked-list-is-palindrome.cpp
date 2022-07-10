// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node * midpointLL(Node * head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node * slow=head;
        Node * fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node * rev(Node * head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node * revhead=rev(head->next);
        head->next->next=head;
        head->next=NULL;
        return revhead;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
       Node * head1=head;
       Node * midpoint=midpointLL(head);
       Node * head2=midpoint->next;
       midpoint->next=NULL;
       Node * revhead1=head1;
       Node * revhead2=rev(head2);
       while(revhead1!=NULL && revhead2!=NULL){
           if(revhead1->data!=revhead2->data){
               return false;
            }
            else{
                revhead1=revhead1->next;
                revhead2=revhead2->next;
            }
       }
       return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends