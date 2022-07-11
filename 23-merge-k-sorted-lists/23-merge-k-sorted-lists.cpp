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
     ListNode * merge(ListNode * l1,ListNode * l2){
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        else if(l1==NULL){
            return l2;
        }
        else if(l2==NULL){
            return l1;
        }
        else{
            ListNode * temp1=l1;
            ListNode * temp2=l2;
            ListNode * newhead=NULL;
            ListNode * newtail=NULL;
            
            while(temp1!=NULL && temp2!=NULL){
                 if(temp1->val<=temp2->val){
                 if(newhead==NULL){
                         newhead=temp1;
                         newtail=temp1;
                     }
                     else{
                         newtail->next=temp1;
                         newtail=temp1;
                     }
                      temp1=temp1->next;
                 }
                 else{
                      if(newhead==NULL){
                         newhead=temp2;
                         newtail=temp2;
                     }
                     else{
                         newtail->next=temp2;
                         newtail=temp2;
                     }
                      temp2=temp2->next;
                 }
            }
            
            while(temp1!=NULL){
                newtail->next=temp1;
                newtail=temp1;
                temp1=temp1->next;
            }
            
            while(temp2!=NULL){
                 newtail->next=temp2;
                 newtail=temp2;
                 temp2=temp2->next;
            }
             newtail->next=NULL;
             return newhead;
        }
       
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
               return NULL;
           }
           else if(lists.size()==1){
               return lists[0];
           }
           ListNode * mergeFinalHead=merge(lists[0],lists[1]);
           for(int i=2;i<lists.size();i++){
               mergeFinalHead=merge(mergeFinalHead,lists[i]);
           }
           
           return mergeFinalHead;
        
    }
};