/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    stack<TreeNode*>asc; 
    stack<TreeNode*>desc;

    TreeNode* getsmall(){
        if(asc.empty()){
            return nullptr;
        }

        TreeNode* small = asc.top();
        asc.pop();

        TreeNode* rightChild = small->right;

        while(rightChild){
            asc.push(rightChild);
            rightChild = rightChild->left;
        }
        return small;

    }
    TreeNode* getBig(){
        if(desc.empty()){
            return nullptr;
        }

        TreeNode* big = desc.top();
        desc.pop();

        TreeNode* leftChild = big->left;

        while(leftChild){
            desc.push(leftChild);
            leftChild= leftChild->right;
        }
        return big;

    }
    bool findTarget(TreeNode* root, int k) {

        if(root ==  nullptr){
            return false;
        }

        TreeNode* t = root;

        while(t){
            asc.push(t);
            t = t->left;
        }
        t = root;
        while(t){
            desc.push(t);
            t = t->right;
        }


        TreeNode* i = getsmall();
        TreeNode* j = getBig();

        while((i && j) && (i != j) && (i->val <= j->val)){
            int sum = i->val + j->val;

            if(sum == k){
                return true;
            }
            if(sum > k ){
                j = getBig();
            }else{
                i = getsmall();
            }
        }

        return false;
        
    }
};