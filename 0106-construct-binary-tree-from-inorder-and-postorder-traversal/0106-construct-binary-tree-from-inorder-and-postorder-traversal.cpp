class Solution {
public:
    int idx;

    TreeNode* fun(vector<int>& postorder, int low, int high,
                  unordered_map<int, int>& mapp) {

        if (low > high) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(postorder[idx]);
        idx--;

        int id = mapp[node->val];

        node->right = fun(postorder, id + 1, high, mapp);
        node->left = fun(postorder, low, id - 1, mapp);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int, int> mapp;

        for (int i = 0; i < inorder.size(); i++) {
            mapp[inorder[i]] = i;
        }

        idx = postorder.size() - 1;

        return fun(postorder, 0, inorder.size() - 1, mapp);
    }
};