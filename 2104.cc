#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;

        long long result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int minVal = INT32_MAX, maxVal = INT32_MIN;
            for (int j = i; j < nums.size(); j++) {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                result += maxVal - minVal;
            }
        }
        return result;
    }
};

int main() {
    Solution solu;
    vector<int> nums{4,23,5};
    cout << solu.subArrayRanges(nums) << endl;
    return 0;
}