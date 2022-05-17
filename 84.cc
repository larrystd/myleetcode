#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n+1);
        dp[0] = heights[0];

        int result = 0;
        int prev_height = heights[0];

        for (int i = 1; i < n; i++) {
            if (prev_height > heights[i]) {
                dp[i-1] = max(heights[i] * (i+1), 2)
            }
        }
    }
};