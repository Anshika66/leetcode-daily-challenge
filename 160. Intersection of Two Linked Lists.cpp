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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * temp = headA;
        unordered_map<ListNode * , int> mapp;

        while(temp != NULL){
            mapp[temp] = 1;
            temp = temp->next;
        }        

        temp = headB;
        while(temp != NULL){
            if(mapp.find(temp) != mapp.end()){
                return temp;
            }

            temp=temp->next;
        }

        return NULL;
    }
};
