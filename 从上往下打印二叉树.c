/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        if (root == NULL) return res;
        que.push(root);
        TreeNode* tmp = NULL;
        while (!que.empty()) {
            tmp = que.front();
            res.push_back(tmp->val);
            if (tmp->left != NULL) que.push(tmp->left);
            if (tmp->right != NULL) que.push(tmp->right);
            que.pop();
        }
        return res;
    }
};