/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans = NULL;
    void fun(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL){
            return ;
        }
        if(node == p || node == q){
            ans = node;
            return ;
        }

        if(node->val > q->val){
            fun(node->left , p , q);
        }else if(node->val < p->val){
            fun(node->right , p ,q);
        }else{
            ans = node;
            return;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < q->val){
            fun(root , p , q);
        }
        if(p->val>q->val){
            fun(root , q , p);
        }
        return ans ;
        
    }
};