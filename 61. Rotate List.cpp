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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }

        int len = 0;
        ListNode*  temp = head;

        while(temp != nullptr){
            len++;
            temp = temp->next;
        }

        int K = k%len;
        
    
        ListNode* prev = nullptr;
        while(K  != 0){
            temp = head ;
            prev =nullptr ;
            while(temp->next != nullptr){
                prev = temp;
                temp = temp->next;

            }

            temp->next = head ;
            prev->next = nullptr;
            head = temp;


            K--;
        }

        return head ;
    }
};
