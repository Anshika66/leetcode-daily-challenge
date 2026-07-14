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
    void fun(TreeNode* node ,vector<vector<int>>&ans ){
        queue<TreeNode*>q;
        q.push(node);

        while(!q.empty()){
            int level = q.size();
            vector<int>temp ;

            while(level--){
                TreeNode* t = q.front();
                q.pop();

                temp.push_back(t->val);

                if(t-> left != nullptr){
                    q.push(t->left);
                }

                if(t->right != nullptr){
                    q.push(t->right);
                }
            }
            ans.push_back(temp);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == nullptr){
            return ans ; 
        }
        fun(root , ans);
        reverse(ans.begin() , ans.end());
        return ans ;
    }
};