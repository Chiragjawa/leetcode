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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0; 
        int lenB=0; 
        ListNode* temp1=headA;
        ListNode* temp2 =headB;
        while(temp1){
            temp1=temp1->next;
            lenA++;
        }
        while(temp2){
            temp2=temp2->next;
            lenB++;
        }
        int a=lenA;
        int b=lenB;
         temp1 = headA;
        temp2 = headB;
        for(int i=0;i<=abs(a-b);i++){
            if(lenA>lenB){
                temp1=temp1->next;
                lenA--;
            }
            if(lenA<lenB){
                temp2=temp2->next;
                lenB--;
            }
        }
        while(temp1  && temp2 ){
            if(temp1 == temp2){
                return temp1;
            }
            temp1 =temp1->next;
            temp2=temp2->next;
        } 
        return NULL;
    }
};