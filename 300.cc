#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        vector<int> dp(n);
        dp[0] = nums[0];
        int maxlength= 0;

        for (int i = 1; i < n; i++) {
            if (dp[maxlength] < nums[i])
                dp[++maxlength] = nums[i];
            else {
                int idx = firstBigger(dp, maxlength, nums[i]);
                dp[idx+1] = nums[i];
            }
        }

        return maxlength+1;
    }

    int firstBigger(const vector<int>& nums, int right, int target) {
        int left = 0;

        while (left <= right) {
            int mid = left + (right-left)/2;
            if  (nums[mid] >= target) {
                right = mid-1;
            }else {
                left = mid+1;
            }
        }

        return right;
    } 
};

int main() {
    vector<int> nums = {4,10,4,3,8,9};
    Solution solu;
    cout << solu.lengthOfLIS(nums) << "\n";

    return 0;
}