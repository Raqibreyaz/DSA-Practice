/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head)
            return nullptr;

        unordered_map<Node*,Node*> mp;

        for(auto temp = head; temp ; temp = temp->next){
            mp[temp] = new Node(temp->val);
        }
        
        // since every node has a copied node mapped
        // so every random node has a copied node too!
        // so point the random's copy then!
        for(auto &[orig,copied]: mp){

            if(orig->random)
                copied->random = mp[orig->random];
            
            if(orig->next)
                copied->next = mp[orig->next];
        }

        return mp[head];
    }
};