/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*  temp = head;
        map<Node* , Node* > mapp;

        while(temp != NULL){
            Node*  newNode = new Node(temp->val);
            mapp[temp] = newNode;
            temp = temp->next;
        }

        temp = head;

        while(temp != NULL){
            Node*  copyNode = mapp[temp];
            copyNode->next = mapp[temp->next];
            copyNode->random = mapp[temp->random];
            temp = temp->next;
        }

        return mapp[head];

        
    }
};
