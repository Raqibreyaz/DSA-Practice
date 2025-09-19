/*

1. reversing a linked list]
2. each time taking k nodes of different windows

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head || !head->next || k == 1)
            return head;
        
        ListNode* i = head;
        ListNode* j = head;
        int count = 1;

        // take a sub-list of size k
        while(j && count < k){
            j = j->next;
            count++;
        }

        // when we dont have enough nodes to reverse in k-group just go back
        if(!j)
            return head;

        // here means i've a sub-list of size k

        // taking the potential head of next sub-list
        ListNode* nextSubHead = j->next;

        // taking the new next subhead of the linked list
        ListNode* newNextSubHead = reverseKGroup(nextSubHead,k);

        // now reverse the k-size list
        j->next = nullptr;
        auto [subHead,subTail] = reverseList(i);

        // linking the separated lists
        subTail->next = newNextSubHead;

        return subHead;
    }

private:
    pair<ListNode*,ListNode*> reverseList(ListNode* head){

        if(!head || !head->next) return {head,head};

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = curr->next;

        while(curr){
            curr->next = prev;

            prev = curr;
            curr = next;

            if(next) next = next->next;
        }

        return make_pair(prev,head);
    }
};