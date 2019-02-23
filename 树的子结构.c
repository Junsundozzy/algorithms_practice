class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    	if (pRoot1 == NULL || pRoot2 == NULL) return false;
    	return isSubtree(pRoot1, pRoot2) || 
    	HasSubtree(pRoot1->left, pRoot2) || 
    	HasSubtree(pRoot1->right, pRoot2);
    }

    bool isSubtree(TreeNode* node1, TreeNode* node2) {
    	if (node2 == NULL) return true;
    	if (node1 == NULL) return false;
    	
    	if (node1->val == node2->val) {
    		return isSubtree(node1->left, node2->left) 
    		&& isSubtree(node1->right, node2->right);
    	} else return false;
    }

};