#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int area_x = 0, area_y = 0, area_z = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            int max_y = 0;
            for (int j = 0; j < n; j++) {
                max_y = max(max_y, grid[i][j]);
            }
            area_y += max_y;
        }

        for (int i = 0; i < m; i++) {
            int max_x = 0;
            for (int j = 0; j < n; j++) {
                max_x = max(max_x, grid[j][i]);
            }
            area_x += max_x;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0)
                    area_z++;
            }
        }
        

        return area_x + area_y + area_z;        
    }
};

int main() {
    vector<vector<int>> grid {{1,0},{0,2}};
    Solution solu;
    cout << solu.projectionArea(grid) << "\n";

    return 0;
}