/*
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev; 

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/

class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        ListNode* temp1 = head ;
        ListNode* temp2 = head->next;
        vector<vector<int>>ans;

        while(temp2->next != nullptr){
            temp2 = temp2->next;
        }

        while(temp1 != temp2 && temp2->next != temp1){
            if((temp1->val + temp2->val) == target){
                vector<int>res;
                res.push_back(temp1->val);
                res.push_back(temp2->val);
                ans.push_back(res);
                temp1 = temp1->next;
                temp2 = temp2->prev;
            }
            else if((temp1->val + temp2->val) > target){
                temp2 = temp2->prev;
            }else{
                temp1 = temp1->next;
            }
        }

        return ans;
    }
};
