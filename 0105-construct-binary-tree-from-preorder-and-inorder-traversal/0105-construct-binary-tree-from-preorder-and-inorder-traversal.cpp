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
    int idx = 0;

    TreeNode* fun(vector<int>& preorder, int low, int high,
                  unordered_map<int, int>& mapp) {

        if (low > high) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;

        int id = mapp[node->val];

        node->left = fun(preorder, low, id - 1, mapp);
        node->right = fun(preorder, id + 1, high, mapp);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> mapp;

        for (int i = 0; i < inorder.size(); i++) {
            mapp[inorder[i]] = i;
        }

        return fun(preorder, 0, inorder.size() - 1, mapp);
    }
};