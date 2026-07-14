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
    void fun(TreeNode* node, vector<vector<int>>&ans){

        queue<TreeNode*> q ; 
        q.push(node);
        int count = 0;

        while(!q.empty()){
            int levelSize = q.size();
            vector<int>temp;
            while(levelSize--){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);

                if(t->left != nullptr){
                    q.push(t->left);
                }

                if(t->right != nullptr){
                    q.push(t->right);
                }
            }
            if(count%2 == 1){
                reverse(temp.begin() , temp.end());
            }
            count++;
            ans.push_back(temp);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == nullptr){
            return ans;
        }
        fun(root , ans);
        return ans ;
        
    }
};