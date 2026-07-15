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
    TreeNode* fun(TreeNode* node , int data){
        if(node == nullptr){
            return nullptr;
        }

        if(node->val == data){
            return node;
        } 

        if(node->val > data){
            return fun(node->left , data);
        }else{
            return fun(node->right , data);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = fun(root , val);
        return ans ;
    }
};