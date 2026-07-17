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
    vector<TreeNode*> res;

    void fun(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        fun(root->left);
        res.push_back(root);
        fun(root->right);
    }

    void recoverTree(TreeNode* root) {

        fun(root);

        TreeNode *first = nullptr, *second = nullptr;

        for (int i = 0; i < res.size() - 1; i++) {

            if (res[i]->val > res[i + 1]->val) {

                if (first == nullptr) {
                    first = res[i];
                    second = res[i + 1];
                } else {
                    second = res[i + 1];
                }
            }
        }

        swap(first->val, second->val);
    }
};