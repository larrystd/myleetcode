#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long sumNum = 0;
        int len = nums.size();
        for (int num : nums) {
            sumNum += num;
        }
        int avgNum1 = sumNum / len;
        int avgNum2 = avgNum1 + 1;
        int result1 = 0;
        int result2 = 0;
        for (int num : nums) {
            result1 += abs(num - avgNum1);
            result2 += abs(num - avgNum2);
        }

        return min(result1, result2);
    }
};