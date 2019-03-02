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
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr) return nullptr;
        TreeNode *pre = nullptr;
        
        middle_search(pRootOfTree, pre);
        TreeNode *res = pRootOfTree;
        while (res->left)
            res = res->left;
        return res;
    }
    
    void middle_search(TreeNode* pNode, TreeNode*& pre) {
        if (!pNode) return;
        middle_search(pNode->left, pre);
        
        pNode->left = pre;
        if (pre) pre->right = pNode;
        pre = pNode;
        
        middle_search(pNode->right, pre);
    }
};