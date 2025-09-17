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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

private:

    ListNode* mergeSort(ListNode* head){

        if(!head || !head->next)
            return head;

        ListNode* midNode = findMiddle(head);

        // taking the second list
        ListNode* head2 = midNode->next;

        // separating both the lists
        midNode->next = nullptr;

       // sorting both the lists
       head = mergeSort(head);
       head2 = mergeSort(head2);

       // merge both the sorted lists and return final head
       return mergeLists(head,head2);
    }

    ListNode* findMiddle(ListNode* head){
        
        if(!head)
            return nullptr;

        ListNode* slow = head,*fast  = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeLists(ListNode* head1, ListNode* head2){

        if(!head1) return head2;
        if(!head2) return head1;

        ListNode* head = nullptr, *temp= nullptr;

        while(head1 && head2){
            
            ListNode* mini = nullptr;

            if(head1->val < head2->val){
                mini = head1;
                head1 = head1->next;
            }
            else{
               mini = head2;
               head2 = head2->next;
            }

            if(temp) {
                temp->next = mini;
                temp = temp->next;
            }
            else{
                temp = mini;
                head = temp;
            } 
        }

        temp->next = head1 ? head1 : head2;

        return head;
    }
};