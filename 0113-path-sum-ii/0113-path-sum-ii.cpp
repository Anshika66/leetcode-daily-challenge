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
    void fun(TreeNode* root, int targetSum,vector<vector<int>>&ans , int sum, vector<int>&temp){
        
        if(root == nullptr){
            return ; 
        }
        temp.push_back(root->val);
        sum =  sum + root->val;

        if(root->left == nullptr && root->right == nullptr){
            if(sum == targetSum){
                ans.push_back(temp);
            }
            temp.pop_back();
            return;
        }

        fun(root->left , targetSum , ans , sum , temp);
        fun(root->right , targetSum , ans , sum , temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        fun(root , targetSum , ans , 0 , temp);
        return ans;
    }
};