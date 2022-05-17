#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> memo;
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, vector<int>(n, -1));

        return 2 * dfs(0, n-1, nums) >= sumNum(0, n-1, nums);
    }

    int dfs(int l, int r, const vector<int>& nums) {
        if (memo[l][r] != -1)
            return memo[l][r];
        
        if (l == r)
            return nums[l];
        return memo[l][r] = sumNum(l, r, nums) - min(dfs(l+1, r, nums), dfs(l, r-1, nums));

    }

    int sumNum(int l, int r, const vector<int>& nums) {
        int ret = 0;
        for (int i = l; i <= r; i++) {
            ret += nums[i];
        }
        return ret;
    }
};

int main() {
    Solution solu;
    vector<int> nums = {0};
    cout << solu.PredictTheWinner(nums) << "\n";

    return 0;
}