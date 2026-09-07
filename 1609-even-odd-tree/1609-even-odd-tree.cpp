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
    bool isEvenOddTree(TreeNode* root) {
        if(root ==nullptr) return true;
        std::queue<TreeNode*> q;
        q.push(root);
        bool evenLevel = true;

        while(!q.empty()){
            int size = q.size();
            int prev = evenLevel ? INT_MIN : INT_MAX;

            while(size-- >0){
                TreeNode* curr = q.front();
                q.pop();

                if(evenLevel ){
                    if(curr->val % 2 == 0 || curr->val <= prev){ return false;
                    }
                } else {
                if(curr->val % 2 != 0 || curr->val >= prev) {
                    return false;
                }
            }

                prev = curr->val;

                if(curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }
            evenLevel = !evenLevel;
        }
        return true;
    }
};