/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
    public:
        ListNode* sortList(ListNode* &head) {
            ListNode* temp = head;
            int zeroCount = 0;
            int oneCount = 0;
            int twoCount = 0;

            while(temp != nullptr){
                if(temp->data== 0){
                    zeroCount++;
                }else if(temp->data == 1){
                    oneCount++;
                }else{
                    twoCount++;
                }

                temp = temp->next;
            }

            temp = head;
            while(zeroCount != 0){
                temp->data = 0;
                zeroCount--;
                temp = temp->next;
            }

            while(oneCount != 0){
                temp->data = 1;
                oneCount--;
                temp = temp->next;
            }

            while(twoCount != 0){
                temp->data = 2;
                twoCount--;
                temp = temp->next;
            }

            return head;
        }
};
