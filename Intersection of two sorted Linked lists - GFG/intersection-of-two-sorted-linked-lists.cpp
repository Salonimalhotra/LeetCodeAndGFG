// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_map<int,int>map;
    Node * temp=head1;
    while(temp!=NULL){
        map[temp->data]++;
        temp=temp->next;
    }
    Node * newhead=NULL;
    Node * newtail=NULL;
    temp=head2;
    while(temp!=NULL){
        if(map.find(temp->data)!=map.end()){
            if(newhead==NULL){
                Node * newnode=new Node(temp->data);
                newhead=newnode;
                newtail=newnode;
                map[temp->data]--;
                if(map[temp->data]==0){
                    map.erase(temp->data);
                }
                temp=temp->next;
            }
            else{
                Node * newnode=new Node(temp->data);
                newtail->next=newnode;
                newtail=newnode;
                map[temp->data]--;
                if(map[temp->data]==0){
                    map.erase(temp->data);
                }
                temp=temp->next;
            }
        }
        else{
            temp=temp->next;
        }
        
    }
    return newhead;
}