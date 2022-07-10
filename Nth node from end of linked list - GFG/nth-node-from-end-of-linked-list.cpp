// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
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


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
//  int len(Node * head){
//      if(head==NULL){
//          return 0;
//      }
//      else{
//          return 1+len(head->next);
//      }
//  }
 int len(Node * head){
     int cnt=0;
     Node * temp=head;
     while(temp!=NULL){
         cnt++;
         temp=temp->next;
     }
     return cnt;
 }
int getNthFromLast(Node *head, int n)
{
       // Your code here
       if(head==NULL){
           return -1;
       }
    //   else if(n==1){
    //       return head->data;
    //   }
       int length=len(head);
    //   cout<<length<<" "<<endl;
       
    //   int length1=len2(head);
    //   cout<<length1<<" "<<endl;
       
       if(length==n){
           return head->data;
       }
       else if(length<n || n<0){
           return -1;
       }
       int i=1;
       Node * temp=head;
       while(i<=length-n){
           temp=temp->next;
           i++;
       }
       return temp->data;
}

