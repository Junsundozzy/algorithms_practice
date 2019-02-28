class Solution {
public:
    stack<int> a;
    stack<int> b;
    void push(int value) {
        a.push(value);
        if (b.empty()) {
            b.push(value);
        }
        else if (b.top() > value) {
            b.push(value);
        }
        else {
            b.push(b.top());
        }
    }
    void pop() {
        a.pop();
        b.pop();
    }
    int top() {
        return a.top();
    }
    int min() {
        return b.top();
    }
};