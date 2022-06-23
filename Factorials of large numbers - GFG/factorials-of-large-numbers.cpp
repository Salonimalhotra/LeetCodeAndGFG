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
  Node(int d){
      this->data=d;
      prev=NULL;
  }
};
void multiply(Node * n1,int x){
    int carry=0;
    Node * temp=n1;
    Node * prevtemp=n1;
    while(temp!=NULL){
        int data=temp->data*x+carry;
        temp->data=data%10;
        carry=data/10;
        prevtemp=temp;
        temp=temp->prev;
    }
    if(carry!=0){
        while(carry!=0 ){
            Node * newNode=new Node(carry%10);
            prevtemp->prev=newNode;
            carry=carry/10;
            prevtemp=prevtemp->prev;
        }
    }
    return;
}
void fill(vector<int>&ans,Node * n1){
    if(n1==NULL){
        return ;
    }
    fill(ans,n1->prev);
    ans.push_back(n1->data);
    return;
}
class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int>ans;
        if(N==0 || N==1){
            ans.push_back(1);
            return ans;
        }
        Node *n1=new Node(1);
        for(int i=2;i<=N;i++){
            multiply(n1,i);
        }
        fill(ans,n1);
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