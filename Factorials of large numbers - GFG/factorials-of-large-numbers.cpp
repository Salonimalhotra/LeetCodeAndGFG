// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Node{
    public:
    int data;
    Node * prev;
    Node(int x){
        data=x;
        prev=NULL;
    }
};
void multiply(Node * tail,int n){
    int carry=0;
    Node * temp=tail;
    Node * previous=tail;
    while(temp!=NULL){
        int data=temp->data*n+carry;
        temp->data=data%10;
        carry=data/10;
        previous=temp;
        temp=temp->prev;
    }
    
    if(carry!=0){
        while(carry!=0){
            Node * newNode=new Node(carry%10);
            carry=carry/10;
            previous->prev=newNode;
            previous=previous->prev;
        }
    }
    return;
}
void helper(vector<int>&ans,Node * tail){
    if(tail==NULL){
        return;
    }
    helper(ans,tail->prev);
    ans.push_back(tail->data);
    return;
}
class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int>ans;
        Node * tail=new Node(1);
        for(int i=2;i<=N;i++){
            multiply(tail,i);
        }
        helper(ans,tail);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends