#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        vector<vector<int>>  dp(len, vector<int>(len));
        for (int i = 0; i < len; i++) {
            dp[i][i] = 0;
        }

        for (int i = len-1; i >= 0; i--) {
            for (int j = i+1; j < len; j++) {
                int temp = max(dp[i+1][j], dp[i][j-1]);
                dp[i][j] = max(temp, min(height[i],height[j])*(j-i));
            }
        }

        return dp[0][len-1];
    }
};

int main() {
    Solution solu;

    vector<int> nums= {1,1};

    cout << solu.maxArea(nums) << endl;

    return 0;
}