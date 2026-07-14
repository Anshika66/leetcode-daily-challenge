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
    bool flipequi(TreeNode* node1, TreeNode* node2){
        if(node1 == nullptr && node2 == nullptr ){
            return true;
        }
        if(node1 == nullptr || node2 == nullptr){
            return false;
        }
        if(node1->val != node2->val){
            return false;
        }

        bool ans1 = (flipequi(node1->left , node2->left) && flipequi(node1->right , node2->right));

        bool ans2 = (flipequi(node1->left , node2->right) && flipequi(node1->right , node2->left));


        return ans1 || ans2;

    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        bool ans = flipequi(root1 , root2);
        return ans;
    }
};