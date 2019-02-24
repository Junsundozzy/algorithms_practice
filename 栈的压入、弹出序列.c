class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() == 0 || popV.size() == 0) return false;
        stack<int> stk;
        for (int i = 0, j = 0; i < pushV.size(); i++) {
            stk.push(pushV[i]);
            while (!stk.empty() && stk.top() == popV[j]) {
                stk.pop();
                j++;
            }
        }
        return stk.empty();
    }
};