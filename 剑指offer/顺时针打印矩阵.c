/*
    思想，用左上和右下的坐标定位出一次要旋转打印的数据，一次旋转打印结束后，往对角分别前进和后退一个单位。
    提交代码时，主要的问题出在没有控制好后两个for循环，需要加入条件判断，防止出现单行或者单列的情况。
 */

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int row = matrix.size();
        int col = matrix[0].size();
        if (row == 0 || col == 0) return res;
        int top = 0, left = 0, bottom = row - 1, right = col - 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) 
                res.push_back(matrix[top][i]);
            for (int i = top + 1; i <= bottom; i++) 
                res.push_back(matrix[i][right]);
            if (top != bottom) {
                for (int i = right - 1; i >= left; i--)
                    res.push_back(matrix[bottom][i]);
            }
            if (left != right) {
                for (int i = bottom - 1; i > top; i--)
                    res.push_back(matrix[i][left]);
            }
            left++, top++, right--, bottom--;
        }
        return res;
    }
};