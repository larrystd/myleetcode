#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int result = 0;
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end(), [](int x, int y) {
            return y < x;
        });
        backtrack(nums,target,0);

        return result;
    }

    void backtrack(vector<int>& nums, int target, int cursum) {

        if (cursum == target) {
            result++;
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + cursum <= target) {
                backtrack(nums,target, cursum+nums[i]);
            }
        }
    }
};

int main() {
    Solution solu;
    vector<int> nums{8};
    cout << solu.combinationSum4(nums, 6) << endl;

    return 0;
}