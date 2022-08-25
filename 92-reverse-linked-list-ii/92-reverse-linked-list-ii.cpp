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
    pair<ListNode *,ListNode *> helper(ListNode * head){
        if(head==NULL || head->next==NULL){
            pair<ListNode * ,ListNode * >p1;
            p1.first=head;
            p1.second=head;
            return p1;
        }
        else{
                pair<ListNode *,ListNode *>smallAns=helper(head->next);
                    pair<ListNode *,ListNode *>finalAns;
                    finalAns.first=smallAns.first;
                    smallAns.second->next=head;
                    head->next=NULL;
                    finalAns.second=head;
                   return finalAns;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
         ListNode * temp=head;
         ListNode * x1=NULL;
         
        int cnt=1;
        while(cnt<left-1 && temp!=NULL){
            temp=temp->next;
            cnt++;
        }
          ListNode * prev1=temp;
        
        if(left==1){
            prev1=NULL;
            x1=head;
        }
        // ListNode * prev1=temp;
        
        if(left!=1){
            x1=prev1->next;
        }
        
        cnt=1;
        temp=head;
        while(cnt<right && temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        
        ListNode * prev2=temp;
     
        ListNode * x2=NULL;
        
           if(prev2->next!=NULL){
                x2=prev2->next;
          }
        
            prev2->next=NULL;
        
            pair<ListNode *,ListNode *> smallAns=helper(x1);
            if(prev1!=NULL){
                prev1->next=smallAns.first;
            }
        
            else if(prev1==NULL){
                head=smallAns.first;
            }
        
            if(x2!=NULL){
                smallAns.second->next=x2;
            }
        
            return head;   
        
    }
};