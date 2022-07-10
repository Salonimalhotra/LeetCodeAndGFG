// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node * midpointLL(Node * head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        else{
            Node * slow=head;
            Node * fast=head->next;
            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow;
        }
    }
    Node * merge(Node * head1,Node * head2){
        if(head1==NULL && head2==NULL){
            return NULL;
        }
        else if(head1==NULL){
            return head2;
        }
        else if(head2==NULL){
            return head1;
        }
        Node * newhead=NULL;
        Node * newtail=NULL;
        
        if(head1->data<=head2->data){
            newhead=head1;
            newtail=head1;
            head1=head1->next;
        }
        else{
            newhead=head2;
            newtail=head2;
            head2=head2->next;
        }
        while(head1!=NULL && head2!=NULL){
             if(head1->data<=head2->data){
                     newtail->next=head1;
                     newtail=head1;
                    head1=head1->next;
             }
             else{
                 newtail->next=head2;
                 newtail=head2;
                 head2=head2->next;
             }
        }
        if(head1!=NULL){
            newtail->next=head1;
            
        }
        else if(head2!=NULL){
            newtail->next=head2;
           
        }
        return newhead;
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node * head1=head;
        Node * midpoint=midpointLL(head);
        Node * head2=midpoint->next;
        midpoint->next=NULL;
        Node * newhead1=mergeSort(head1);
        Node * newhead2=mergeSort(head2);
        Node * finalhead=merge(newhead1,newhead2);
        return finalhead;
        
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends