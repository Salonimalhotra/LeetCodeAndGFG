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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int,int>mp;
        ListNode * temp=head;
        while(temp!=NULL){
            mp[temp->val]++;
            temp=temp->next;
        }
        
        ListNode * dummyNode=new ListNode(-1);
        ListNode * helper=dummyNode;
        
        temp=head;
        while(temp!=NULL){
            if(mp[temp->val]>1){
                temp=temp->next;
            }
            else{
                helper->next=temp;
                helper=temp;
                temp=temp->next;
            }
        }
        helper->next=NULL;
        return dummyNode->next;
    }
};