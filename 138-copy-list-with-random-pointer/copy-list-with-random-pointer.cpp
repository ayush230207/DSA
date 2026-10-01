class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;

        unordered_map<Node*,Node*> pointer;
        Node* newHead= new Node(head->val);
        Node* newTemp= newHead;
        Node* oldTemp=head;
        pointer[oldTemp]= newTemp;
        oldTemp= head->next;

        while(oldTemp != NULL){
            Node* copy= new Node(oldTemp->val);
            newTemp->next= copy;
            newTemp=copy;
            pointer[oldTemp]= newTemp;
            oldTemp= oldTemp->next;
        }

        oldTemp= head;
        newTemp= newHead;

        while(oldTemp != NULL){
            // Corrected line below:
            newTemp->random = pointer[oldTemp->random];
            
            newTemp= newTemp->next;
            oldTemp= oldTemp->next;
        }

        return newHead;
    }
};