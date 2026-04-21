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
    ListNode* findNthNode(ListNode* head , int k){
        int cnt = 1;
        ListNode* temp = head;

        while(temp != nullptr){
            if(cnt == k) return temp; 
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }

        ListNode* tail = head;
        int len = 1;
        while(tail->next != nullptr){
            len++;
            tail = tail->next;
        }

        tail->next = head;

        int K = k%len;

        ListNode* newLastNode = findNthNode(head , len-K);
        head = newLastNode->next ;
        newLastNode->next = nullptr;
        
        return head;

    }
};
