class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> dp(array.size(), 0);
        dp[0] = array[0];
        
        int res = dp[0];
        for (int i = 1; i < array.size(); i++) {
            dp[i] = max(dp[i-1] + array[i], array[i]);
            if (dp[i] > res) {
                res = dp[i];
            }
        }
        return res;
    }
};