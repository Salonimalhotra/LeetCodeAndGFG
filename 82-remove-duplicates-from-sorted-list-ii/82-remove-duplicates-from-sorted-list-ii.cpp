/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode * temp=head;
        ListNode * prev=NULL;
        ListNode * firsthead=NULL;
        unordered_map<int,int>mp;
        while(temp!=NULL){
           if(temp->next!=NULL && temp->next->val==temp->val){
               cout<<temp->val<<"included here"<<endl;
               mp[temp->val]++;
               temp=temp->next;
           }
           else if(temp->next==NULL || (temp->next!=NULL && temp->val!=temp->next->val)){
                if(mp.find(temp->val)==mp.end()){
                      if(prev==NULL){
                          cout<<temp->val<<"included here1"<<endl;
                          firsthead=temp;
                          prev=temp;
                          temp=temp->next;
                      }
                    else{
                        cout<<temp->val<<"included here2"<<endl;
                        if(temp->val==2){
                            cout<<"prev->val"<<prev->val<<endl;
                        }
                        prev->next=temp;
                        prev=temp;
                        temp=temp->next;
                    }
                 }
               else{
                   temp=temp->next;
               }
            }
            else{
                temp=temp->next;
            }
        }
          if(prev==NULL){
              return NULL;
          }
          prev->next=NULL;
          return firsthead;
    }
};