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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry=0;
        ListNode* temp1 =l1;
        ListNode* temp2 =l2;
        while(temp1!=NULL || temp2!=NULL){
            int sum = carry;
            if(temp1) sum+=temp1->val;
            if(temp2) sum+=temp2->val;
            ListNode* newn =  new ListNode(sum%10);
            curr->next = newn;
            curr= curr->next;
            carry = sum/10;
            if(temp1) temp1= temp1->next;
            if(temp2) temp2= temp2->next;
        }
        if(carry !=0){
            ListNode* carr = new ListNode(carry);
            curr->next = carr;
        }
        return dummy->next;
    }
};