/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (!pHead) return NULL;
        RandomListNode *currNode = pHead;
        while (currNode) {
            RandomListNode *newNode = new RandomListNode(currNode->label);
            newNode->next = currNode->next;
            currNode->next = newNode;
            currNode = newNode->next;
        }
        currNode = pHead;
        while (currNode) {
            RandomListNode *node = currNode->next;
            if (currNode->random) {
                node->random = currNode->random->next;
            }
            currNode = node->next;
        }
        RandomListNode *pClonehead = pHead->next;
        RandomListNode *tmp = NULL;
        currNode = pHead;
        while (currNode->next) {
            tmp = currNode->next;
            currNode->next = tmp->next;
            currNode = tmp;
        }
        return pClonehead;
        
    }
};