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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr){
            ListNode* nextNode = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);

        if (n == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return reverse(head);
        }
        

        ListNode* temp = head ;
        ListNode* prev = nullptr;
        for (int i = 1; i < n; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            return reverse(head);  
        }

        prev->next  = temp->next;
        temp->next = nullptr;

        delete(temp);

        ListNode* ans = reverse(head);
        return ans ;
    }
};
