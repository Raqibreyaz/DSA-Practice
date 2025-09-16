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
    ListNode* reverseList(ListNode* head) {
        auto [newHead, newTail] = reverse(head);

        return newHead;
    }

private:
    pair<ListNode*,ListNode*> reverse(ListNode* node){

        // when linked list length <= 1
        if(node == nullptr || node->next == nullptr)
            return {node,node};

        // reverse the len - 1 part
        auto [head,tail] = reverse(node->next);

        // now reverse the current node
        tail->next = node;
        node->next = nullptr;

        // return current head and tail
        return {head,node};
    }
};