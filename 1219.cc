#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    const int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> visited;
    int m;
    int n;
    int maxval;
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        if (m == 0)
            return 0;
        n = grid[0].size();
        maxval = 0;
        visited.assign(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    dfs(i, j, grid, grid[i][j]);
                }
            }
        }

        return maxval;
    }


    void dfs(int x, int y, vector<vector<int>>& grid, int curval) {
        if (curval > maxval) {
            maxval = curval;
        }

        visited[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int dx = x + direction[i][0];
            int dy = y + direction[i][1];
            if (dx < 0 || dx >= m || dy < 0 || dy >= n) {
                continue;
            }
            if (visited[dx][dy] || grid[x][y] == 0)
                continue;
            dfs(dx, dy, grid, curval+grid[dx][dy]);
        }

        visited[x][y] = 0;
    }
};

int main() {
    vector<vector<int>> grid{{0,6,0},{5,8,7},{0,9,0}};

    Solution solu;
    cout << solu.getMaximumGold(grid) << "\n";

    return 0;
}