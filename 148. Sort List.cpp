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
    ListNode* middleEle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next ->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* mergeTwoList(ListNode* list1  , ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                temp = list2;
                list2= list2->next;
            }
        }
        if(list1){
            temp->next = list1;
        }else{
            temp->next= list2;
        }

        return dummyNode->next;

    }
    ListNode* sortList(ListNode* head) {
        // ListNode* temp = head;
        // vector<int>arr;
        // while(temp != nullptr){
        //     arr.push_back(temp->val);
        //     temp = temp->next;
        // }

        // sort(arr.begin() , arr.end());

        // temp = head;

        // int i = 0;
        // while(temp != nullptr && i<arr.size()){
        //     temp->val = arr[i];
        //     temp= temp->next ; 
        //     i++;
        // }

        // return head;



        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* middle = middleEle(head);
        ListNode* lefthead = head ; 
        ListNode* righthead = middle->next;

        middle->next = nullptr;

        lefthead = sortList(lefthead);
        righthead = sortList(righthead);

        return mergeTwoList(lefthead , righthead);

        
    }
};
