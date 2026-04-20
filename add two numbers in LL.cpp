class Solution {
public:
    void insertAtTail(ListNode* &head, ListNode* &tail, int digit){
        ListNode* temp = new ListNode(digit);
        
        if(head == NULL){
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    
    ListNode* add(ListNode* first, ListNode* second){
        int carry = 0;
        ListNode* anshead = NULL;
        ListNode* anstail = NULL;
        
        while(first != NULL || second != NULL || carry != 0){
            int val1 = (first != NULL) ? first->val : 0;
            int val2 = (second != NULL) ? second->val : 0;
            
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            insertAtTail(anshead, anstail, digit);
            carry = sum / 10;
            
            if(first != NULL) first = first->next;
            if(second != NULL) second = second->next;
        }
        
        return anshead;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        ListNode* ans = add(l1, l2);
        
        
        
        return ans;
    }
};
