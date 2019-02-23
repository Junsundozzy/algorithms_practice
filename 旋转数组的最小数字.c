//binary search
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0)
            return 0;
        int left = 0, right = rotateArray.size() - 1;
        int mid = 0;
        while (left < right) {
            mid = (left + right) / 2;
            if (rotateArray[mid] > rotateArray[right]) {
                left = mid + 1;
            }
            else if (rotateArray[mid] < rotateArray[right]) {
                right = mid;
            }
            else {
                right--;
            }
        }
        return rotateArray[left];
    }
};