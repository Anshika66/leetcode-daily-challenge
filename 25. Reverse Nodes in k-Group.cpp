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
            curr->next = prev ; 
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
    ListNode* findKthNode(ListNode* temp , int k ){
        k -= 1;
        while(temp != nullptr && k >0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast  = nullptr;

        while(temp != nullptr){
            ListNode* kthNode = findKthNode(temp , k);
            if(kthNode == nullptr){
                if(prevLast){
                    prevLast->next = temp;
                }

                break;
            }

            ListNode* nextNode = kthNode->next;

            kthNode->next = nullptr ;
            reverse(temp);

            if(temp == head){
                head = kthNode ; 
            }else{
                prevLast->next = kthNode;
            }

            prevLast = temp ; 
            temp = nextNode;
        }

        return head;
    }
};
