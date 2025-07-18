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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *prev=NULL;
        ListNode *curr=slow->next;
        
        while(curr!=NULL){
            ListNode *next_node=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next_node;
        }
        while(prev!=NULL){
            if(prev->val != head->val){
                 return false;
            }
            prev=prev->next;
            head=head->next;
        }
        return true;
    }
};