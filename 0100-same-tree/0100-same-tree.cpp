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
    bool fun(TreeNode* node1, TreeNode* node2){
        if(node1 == nullptr && node2 == nullptr){
            return true;
        }
        if(node1 == nullptr  || node2 == nullptr){
            return false;
        }

        if(node1->val != node2->val){
            return false;
        }

        bool ans1 = fun(node1->left , node2->left);
        bool ans2 = fun(node1->right , node2->right);

        return ans1 & ans2;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = fun(p  , q);
        return ans;
    }
};