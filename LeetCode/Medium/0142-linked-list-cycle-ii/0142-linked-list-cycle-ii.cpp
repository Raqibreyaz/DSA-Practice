/*

L1 = distance of loop starting from head
L2 = distance of meet of slow and fast from loop start
k = no of nodes in the loop
fast covers = 2 * slow's distance 
slow covered = L1 + L2
fast covered = L1 + L2 + nk(assuming fast has covered loop n times)

=> 2 * (L1 + L2) = L1 +  L2 + nk
=> L1 + L2 = nk
=> L1 = nk - L2
=> it means point where slow and fast meets is L1 distance away from loop start
=> means if i start from head and go forward + start from slow and fast meet and go forward then will meet at loop start!

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;

        while(fast && fast->next){

            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) break;
        }

        // return null when no loop present
        if(!fast || !fast->next) return nullptr;

        while(temp != slow){
            slow = slow->next;
            temp = temp->next;
        }

        return temp;
    }
};