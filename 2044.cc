#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int result;
    int maxxor;
    int countMaxOrSubsets(vector<int>& nums) {
        result = 0;
        maxxor = INT32_MIN;
        dfs(nums, 0, 0);

        return result;
    }

    void dfs(const vector<int>& nums, int idx, int curxor) {

        if (curxor > maxxor) {
            maxxor = curxor;
            result = 1;
        } else if (curxor == maxxor) {
            result++;
        }
        if (idx >= nums.size())
            return;

        for (int i = idx; i < nums.size(); i++) {

            dfs(nums, i+1,curxor | nums[i]);
        }
    }
};

int main() {
    vector<int> nums{3,2,1,5};
    Solution solu;
    cout << solu.countMaxOrSubsets(nums) << "\n";

    return 0;
}