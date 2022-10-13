/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node==NULL){
          return;
        }
       ListNode * prev=node;
       ListNode * nextNode=node->next;
       prev->val=nextNode->val;
       prev->next=nextNode->next;
       delete nextNode;
      return;
    }
};