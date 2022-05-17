/*
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        
        n = len(coins)
        dp = [[0]*(amount+1) for _ in range(n+1)]   # 初始化
        for i in range(n+1):    # 合法的初始化：凑出金额0的组合只有一种，即不选任何硬币
            dp[i][0] = 1
        
        # 完全背包：优化后的状态转移
        for i in range(1, n+1):         # 第一层循环：遍历硬币
            for j in range(amount+1):   # 第二层循环：遍历背包
                if j < coins[i-1]:      # 容量有限，无法选择第i个硬币
                    dp[i][j] = dp[i-1][j]
                else:                   # 可选择第i个硬币
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]
        
        return dp[n][amount]
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount+1));

        for (int i = 0; i < n; i++) 
            dp[i][0] = 1;   // 初始化
        
        for (int j = 1; j <= amount; j++) {
            if (j % coins[0] == 0)
                dp[0][j] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j < coins[i])
                    dp[i][j] = dp[i-1][j];  // 容量有限，无法选择第i个硬币
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]]; // 可选择第i个硬币
                }
            }
        }

        return dp[n-1][amount];

    }
};

int main() {
    vector<int> coins = {1, 2, 5};

    Solution solu;

    cout << solu.change(5, coins) << "\n";

    return 0;
}