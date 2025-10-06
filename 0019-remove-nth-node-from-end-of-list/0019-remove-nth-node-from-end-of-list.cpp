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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* prev = NULL;
        ListNode* next =NULL;
        if(!head || head->next==NULL){
            return NULL;
        }

        int count=0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        ListNode* d =head;
        int r=count-n;
        for(int i=0;i<r-1;i++){
            d=d->next;
        }
        if(count==n){
            head=head->next;
            return head;
        }
        prev = d;
        if(n==1){
            prev->next=NULL;
            return head;
        }
        d=d->next;
        next =d->next;
        prev->next = next;
        return head;
    }
};