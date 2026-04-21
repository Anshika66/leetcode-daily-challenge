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
    void insertCopyInBetween(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
    }
    void connectRandomPointers(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copyNode = temp->next;
            if(temp->random){
                copyNode->random = temp->random->next;
            }else{
                copyNode->random = NULL;
            }
            temp = temp->next->next;
        }
    }
    Node* getdeepcopylist(Node* head){
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        Node* temp = head;

        while(temp != NULL){
            res->next = temp->next;
            res = res->next ;

            temp->next=temp->next->next;
            temp= temp->next;
        }
        return dummyNode->next;
    }
    Node* copyRandomList(Node* head) {
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getdeepcopylist(head);

    }
};
