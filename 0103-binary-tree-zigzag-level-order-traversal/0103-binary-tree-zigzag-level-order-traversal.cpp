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
    void fun(TreeNode* root, vector<vector<int>>& ans) {
        queue<TreeNode*> q;
        q.push(root);

        bool lefttoright = true;

        while (!q.empty()) {
            int levsize = q.size();
            vector<int> temp(levsize);

            int first = 0;
            int last = levsize - 1;

            while (levsize--) {
                TreeNode* t = q.front();
                q.pop();

                if (lefttoright == true) {
                    temp[first] = t->val;
                    first++;
                } else {
                    temp[last] = t->val;
                    last--;
                }

                if (t->left != nullptr) {
                    q.push(t->left);
                }

                if (t->right != nullptr) {
                    q.push(t->right);
                }
            }

            ans.push_back(temp);
            lefttoright = !lefttoright;
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == nullptr) {
            return ans;
        }

        fun(root, ans);
        return ans;
    }
};