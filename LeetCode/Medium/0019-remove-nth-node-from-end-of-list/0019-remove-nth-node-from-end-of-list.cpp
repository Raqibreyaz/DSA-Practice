/*
1. since we have to do it in single pass and we dont know the no of nodes in the list
2. but we do have n telling us the node to be removed
3. so why not to maintain a window of size n+1 nodes?
4. here we will go till last node so that at last our window start will be n-1th node from last
*/


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
        int distance = 0;
        ListNode* i = head;
        ListNode* j = head;

        while (j && j->next) {
            if (distance < n) {
                distance++;
            } else
                i = i->next;
            j = j->next;
        }

        // when there are >n nodes
        if (distance == n) {
            i->next = i->next->next;
        }

        // when there are exactly n nodes
        else if (distance == n - 1)
            head = head->next;

        // when there are <n nodes
        // do nothing

        return head;
    }
};