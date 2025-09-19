/*

1. maintain a window of size k+1
2. traverse the list till tail node
3. then remove link of the window and move the window head

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
    ListNode* rotateRight(ListNode* head, int k) {

        int len = findLen(head);

        k = len == 0 ? 0: k % len;

        if(!head || !head->next || k == 0)
            return head;

        ListNode* i = head;
        ListNode* j = head;
        int distance = 0;

        while(j && j->next){
            if(distance < k)
                distance++;
            else i = i->next;
            j = j->next;
        }

        // when no of nodes to rotate == k then no need to rotate
        if(distance == k - 1)
            return head;

        ListNode* temp = head;
        
        // new head node
        head = i->next;

        // new tail node
        i->next = nullptr;

        j->next = temp;

        return head;
    }

private:
    int findLen(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }

        return len;
    }
};