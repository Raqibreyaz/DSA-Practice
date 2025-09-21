/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        auto [h,t] = flattenList(head);

        return h;
    }

private:
    pair<Node*,Node*> flattenList(Node* head){

        if(!head)
            return {nullptr,nullptr};

        auto [nextHead,nextTail] = flattenList(head->next);
        auto [childHead,childTail] = flattenList(head->child);

        if(childTail){

            if(nextHead) nextHead->prev = childTail;

            childTail->next = nextHead;
            head->next = childHead;
            childHead->prev = head;
            head->child = nullptr;
        }
        else{
            head->next = nextHead;
            if(nextHead) nextHead->prev = head;
        }

        Node* tail = nextTail ? nextTail : (childTail ? childTail : head);

        return {head,tail};
    }
};