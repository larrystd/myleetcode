#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(m+1, vector<int>(n+1)));

        vector<pair<int, int>> num_01;
        for (int i = 0; i < size; i++) {
            int num_0 = 0;
            int num_1 = 0;
            for (char c : strs[i]) {
                if (c == '0')
                    num_0++;
                else  
                    num_1++;
            }
            num_01.push_back({num_0, num_1});
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j <= m; j ++) {
                for (int k = 0; k <= n; k++) {
                    if (num_01[i].first >j || num_01[i].second > k) {
                        if (i == 0)
                            dp[0][j][k] = 0;
                        else
                            dp[i][j][k] = dp[i-1][j][k];
                    }else {
                        if (i == 0)
                            dp[0][j][k] = 1;
                        else  
                            dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-num_01[i].first][k-num_01[i].second]+1);
                    }
                }
            }
        }

        return dp[size-1][m][n];
    }
};

int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};

    int m = 1;
    int n = 1;
    Solution solu;

    cout << solu.findMaxForm(strs, 5, 3) << "\n";

    return 0;
}