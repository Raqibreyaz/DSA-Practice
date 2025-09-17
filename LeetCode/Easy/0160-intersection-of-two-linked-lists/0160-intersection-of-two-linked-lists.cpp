/*

1. we can't reverse the list
2. here actual memory address of nodes are same for intersection
3. since for intersection we usually start from last means we dont care how many irrelevant nodes are at starting
4. so we will skip nodes from starting , but how many? difference between length of lists

*/


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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        int len1 = lengthOfList(headA);
        int len2 = lengthOfList(headB);

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        for(int i = 1; i <= len1 - len2; i++, temp1 = temp1->next);
        for(int i = 1; i <= len2 - len1; i++, temp2 = temp2->next);

        for (;
             temp1 && temp2;
             temp1 = temp1->next, temp2 = temp2->next) {

           if(temp1 == temp2)   return temp1;
        }

        return nullptr;
    }

private:
    int lengthOfList(ListNode* head){
        int len = 0;
        for(ListNode* temp = head; temp ; temp = temp->next, len++);
        return len;
    }
};