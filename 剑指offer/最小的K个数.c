class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        int len = input.size();
        if (len <= 0 || k <= 0 || len < k) return res;
        
        multiset<int, greater<int> > leastNumbers;
        multiset<int, greater<int> >::iterator iter;
        
        vector<int>::iterator it = input.begin();
        for (; it != input.end(); it++) {
            if (leastNumbers.size() < k) {
                leastNumbers.insert(*it);
            }
            else {
                iter = leastNumbers.begin();
                if (*it < *iter) {
                    leastNumbers.erase(iter);
                    leastNumbers.insert(*it);
                }
            }
        }
        
        for (iter = leastNumbers.begin(); iter != leastNumbers.end(); iter++) {
            res.push_back(*iter);
        }
        
        return res;
    }
};