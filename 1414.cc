#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if (k == 1)
            return 1;
        vector<int> nums;
        nums.push_back(1);
        nums.push_back(1);

        int firstidx = 0;
        int secondidx = 1;
        while (nums[firstidx] + nums[secondidx] <= k) {
            if (nums[firstidx] + nums[secondidx] == k)
                return 1;
            nums.push_back(nums[firstidx] + nums[secondidx]);
            firstidx++;
            secondidx++;
        }

        int left = k;
        int idx = secondidx;
        int result = 0;
        
        while (idx >= 0 && left != 0) {
            result += left/nums[idx];
            left %= nums[idx];

            idx--;
        }

        return result;

    }
};

int main() {
    Solution solu;

    cout << solu.findMinFibonacciNumbers(19) << "\n";

    return 0;
}