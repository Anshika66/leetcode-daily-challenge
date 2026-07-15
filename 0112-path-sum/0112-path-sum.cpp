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
    bool res = false;
    void fun(TreeNode* root, int targetSum , int sum){
        if(root == nullptr){
            return ;
        }
        sum = sum + root->val;
        if(root->left == nullptr && root->right == nullptr){
            if(sum == targetSum){
                res = true;
                return;
            }
        }

        fun(root->left , targetSum , sum);
        fun(root->right , targetSum , sum);
        return ; 
    } 
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root == nullptr){
            return false;
        }

        int sum = 0;

        fun(root , targetSum , 0);
        return res;
    }
};