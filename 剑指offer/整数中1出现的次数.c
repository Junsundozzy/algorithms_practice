class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int count = 0;
        for (int i = 1; i <= n; i *= 10) {
            int a = n/i, b = n%i;
            if (a%10 == 0)
                count += a/10 * i;
            else if (a%10 == 1)
                count += (a/10 * i) + (b+1);
            else
                count += (a/10 + 1) * i;
        }
        return count;
        }
    
};