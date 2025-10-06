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
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        ListNode* temp1 = head;
        if(!head){
            return false;
        }

        while(temp1 != NULL && temp1->next){
            temp=temp->next;
            temp1=temp1->next->next;

            if(temp==temp1){
                return true;
            }

        }
        return false;
    }
};