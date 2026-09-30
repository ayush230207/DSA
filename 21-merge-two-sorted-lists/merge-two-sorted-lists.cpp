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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* curr= list1;
        ListNode* prev= NULL;
        ListNode* temp= NULL;

        while(curr!= NULL && list2!= NULL){
            if(list2->val < curr->val){
                temp= list2;
                list2= list2->next;
                temp->next= curr;

                if(prev == NULL) list1= temp;
                else prev->next= temp;

                prev= temp;
            }else{
                prev=curr;
                curr= curr->next;
            }
        }

        if(list2 != NULL) prev->next= list2;

        return list1;
    }
};