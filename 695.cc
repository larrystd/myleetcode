#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n));
        int maxarea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0)  {
                    list<pair<int,int>> que;
                    que.push_back({i, j});
                    visited[i][j] = 1;

                    int curarea = 0;
                    while (!que.empty()) {
                        auto& p = que.front();

                        for (int k = 0; k < 4; k++) {
                            int next_x = p.first+directions[k][0];
                            int next_y = p.second+directions[k][1];

                            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || visited[next_x][next_y] == 1 || grid[next_x][next_y] == 0)
                                continue;  
                            que.push_back({next_x, next_y});
                            visited[next_x][next_y] = 1;
                        }
                        que.pop_front();
                        curarea++;
                    }
                    maxarea = max(maxarea, curarea);
                } 
            }
        }

        return maxarea;
    }
};

int main() {
    Solution solu;

    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};

    cout << solu.maxAreaOfIsland(grid) << "\n";

    return 0;
}