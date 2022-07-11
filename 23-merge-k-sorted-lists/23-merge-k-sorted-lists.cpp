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
#include<queue>
class cmp{
    public:
   bool operator()(const ListNode* a, const ListNode* b)
    {
        return a->val> b->val;
    }
  
};
class Solution {
public:
//      ListNode * merge(ListNode * l1,ListNode * l2){
//         if(l1==NULL && l2==NULL){
//             return NULL;
//         }
//         else if(l1==NULL){
//             return l2;
//         }
//         else if(l2==NULL){
//             return l1;
//         }
//         else{
//             ListNode * temp1=l1;
//             ListNode * temp2=l2;
//             ListNode * newhead=NULL;
//             ListNode * newtail=NULL;
            
//             while(temp1!=NULL && temp2!=NULL){
//                  if(temp1->val<=temp2->val){
//                  if(newhead==NULL){
//                          newhead=temp1;
//                          newtail=temp1;
//                      }
//                      else{
//                          newtail->next=temp1;
//                          newtail=temp1;
//                      }
//                       temp1=temp1->next;
//                  }
//                  else{
//                       if(newhead==NULL){
//                          newhead=temp2;
//                          newtail=temp2;
//                      }
//                      else{
//                          newtail->next=temp2;
//                          newtail=temp2;
//                      }
//                       temp2=temp2->next;
//                  }
//             }
            
//             while(temp1!=NULL){
//                 newtail->next=temp1;
//                 newtail=temp1;
//                 temp1=temp1->next;
//             }
            
//             while(temp2!=NULL){
//                  newtail->next=temp2;
//                  newtail=temp2;
//                  temp2=temp2->next;
//             }
//              newtail->next=NULL;
//              return newhead;
//         }
       
//     }
   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
          if(lists.size()==0){
               return NULL;
           }
           else if(lists.size()==1){
               return lists[0];
           }
        
            priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
           int i=0;
        while(i<lists.size()){
            if(lists[i]!=NULL){
              pq.push(lists[i]);              
            }
          
            i++; 
        }
        ListNode * newhead=NULL;
        ListNode * newtail=NULL;
        
        while(pq.size()!=0){
            ListNode * topNode=pq.top();
            ListNode * nextNode=NULL;
            
            if(topNode->next!=NULL){
                nextNode=topNode->next;
                pq.push(nextNode);
                topNode->next=NULL;
            }
            pq.pop();
            if(newhead==NULL){
                newhead=topNode;
                newtail=topNode;
                
            }
            else{
                newtail->next=topNode;
                newtail=topNode;
            }
            
        }
        
        return newhead;          
        
    }
};