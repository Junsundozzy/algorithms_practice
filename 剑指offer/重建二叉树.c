/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int length = vin.size();
        if (length == 0) {
            return NULL;
        }
        vector<int> right_pre, right_vin, left_pre, left_vin;
        TreeNode *head = new TreeNode(pre[0]);
        int ind = 0;
        for (int i = 0; i < length; i++) {
            if (vin[i] == pre[0]) {
                ind = i;
                break;
            }
        }
        
        for (int i = 0; i < ind; i++) {
            left_pre.push_back(pre[i+1]);
            left_vin.push_back(vin[i]);
        }
        
        for (int i = ind+1; i < length; i++) {
            right_pre.push_back(pre[i]);
            right_vin.push_back(vin[i]);
        }
        head->left = reConstructBinaryTree(left_pre, left_vin);
        head->right = reConstructBinaryTree(right_pre, right_vin);
        return head;
    }
};