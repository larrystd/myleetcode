#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3)
            return 0;
        vector<int> leftmax(n);
        vector<int> rightmax(n);

        for (int i = 1; i < n; i++) {
            leftmax[i] = max(leftmax[i-1], height[i-1]);
        }

        for (int i = n-2; i >= 0; i--) {
            rightmax[i] = max(rightmax[i+1], height[i+1]);
        }

        int result = 0;
        for (int i = 1; i < n-1; i++) {
            result += max(min(leftmax[i],rightmax[i]) - height[i], 0);
        }

        return result;
    }
};

int main() {
    Solution solu;

    vector<int> height{0, 1, 0,1};
    cout << solu.trap(height) << "\n";

    return 0;
}