#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int INF = 0x3f3f3f3f;
    int coinChange(vector<int>& coins, int amount) {
         int n = coins.size();
         vector<vector<int>> f (n + 1, vector<int>(amount + 1, INF));

        for (int i = 0; i <= n; i++) 
            f[i][0] = 0;  
         for(int i = 1; i <= n; i++)
         {
         	int val = coins[i-1];
            for(int j = 0; j <= amount; j++) {
                if (j < val)
                    f[i][j] = f[i - 1][j];
                for(int k = 0; k*val <= j; k++)
                {
                    f[i][j] = min(f[i][j] , f[i-1][j-k*val] + k);   // 得到f[i-1][j-k*val] + k的最小值
                }
            }
         }	 
        if (f[n][amount] == INF) f[n][amount] = -1;
        return f[n][amount];
    }

    int coinChangeV2(vector<int>& coins, int amount) {
         int n = coins.size();
         vector<vector<int>> f (n + 1, vector<int>(amount + 1, INF));

         for (int i = 0; i <= n; i++) 
            f[i][0] = 0; 
         for(int i = 1; i <= n; i++)
         {
         	int val = coins[i-1];
            for(int j = 0; j <= amount; j++) {
                if (j >= val) {
                    f[i][j] = min(f[i - 1][j] , f[i][j-val] + 1);
                }else {
                    f[i][j] = f[i - 1][j];
                }
            }
         }	 
        if (f[n][amount] == INF) f[n][amount] = -1;
        return f[n][amount];
    }

    int coinChangeV3(vector<int>& coins, int amount) {
         int n = coins.size();
         vector<int> f (amount + 1, INF);

         f[0] = 0;
         for(int i = 1; i <= n; i++)
         {
         	int val = coins[i-1];
            for(int j = 0; j <= amount; j++) {
                if (j >= val) {
                    f[j] = min(f[j] , f[j-val] + 1);
                }
            }
         }	 
        if (f[amount] == INF) f[amount] = -1;
        return f[amount];
    }
};

int main() {
    Solution solu;

    vector<int> coins{186,419,83,408};
    cout << solu.coinChangeV3( coins, 6249) << "\n";
}