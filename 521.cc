#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b)
            return -1;
        int len_a = a.size(), len_b = b.size();
        vector<vector<int>> dp(len_a+1, vector<int>(len_b+1));

        for (int i = 1; i <= len_a; i++) {
            for (int j = 1; j <= len_b; j++) {
                if (a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else   
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return len_a > len_b ? len_a - dp[len_a][len_b] : len_b - dp[len_a][len_b];
    }
};

int main() {
    Solution solu;

    cout << solu.findLUSlength("aaa", "aaa") << "\n";

    return 0;
}