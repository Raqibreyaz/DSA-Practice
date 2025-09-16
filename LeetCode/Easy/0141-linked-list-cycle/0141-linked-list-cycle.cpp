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
        unordered_set<ListNode*> track;

        ListNode* temp = head;
        while(temp != nullptr){
            
            // checking if this node is already visited
            if(track.contains(temp))
                return true;

            track.insert(temp);
            temp = temp->next;
        }

        return false;
    }
};