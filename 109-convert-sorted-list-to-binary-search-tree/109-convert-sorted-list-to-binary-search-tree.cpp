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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        
        if(head->next==NULL)
            return new TreeNode(head->val);
        
        ListNode *prev = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
		
        //Step 1. Find the mid of the list.

        while(fast!=NULL && fast->next!=NULL){
            
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            
        }
        prev->next = NULL;
        //Step 2. Make a new node of the tree(say N) with the same value as the mid element found(mid->val).
        TreeNode *root = new TreeNode(slow->val);
		
		//Step 3. Divide the list into two parts from the mid element i.e. a left part and a right part.
		 //After dividing the list into two make the left of the node(N->left) equal to the mid of //the left list and similarly make the right of the node(N->right) equal to the mid of the right list.
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
      
        return root;   
    }
};