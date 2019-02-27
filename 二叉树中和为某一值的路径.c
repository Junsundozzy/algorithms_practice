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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > res;
        vector<int> path;
        if (root) 
            dfs(root, res, path, expectNumber);
        return res;
    }
    
    void dfs(TreeNode* root, vector<vector<int> > &res, vector<int> &path, int s) {
        path.push_back(root->val);
        if (!root->left && !root->right) {
            if (s == root->val)
                res.push_back(path);
        }
        if (root->left)
            dfs(root->left, res, path, s-root->val);
        if (root->right)
            dfs(root->right, res, path, s-root->val);
        path.pop_back();
    }
};