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
    void fun(TreeNode* node, vector<vector<int>>& ans) {
        queue<TreeNode*> q;
        q.push(node);

        while (!q.empty()) {
            int level = q.size();
            vector<int> t;

            while (level--) {
                TreeNode* temp = q.front();
                q.pop();

                t.push_back(temp->val);

                if (temp->left != nullptr)
                    q.push(temp->left);

                if (temp->right != nullptr)
                    q.push(temp->right);
            }

            ans.push_back(t);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        fun(root, ans);

        return ans;
    }
};