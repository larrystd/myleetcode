#include <vector>
#include <iostream>
#include <queue>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();

        queue<pair<int,int>> waterqueue;
        vector<vector<int>> result(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isWater[i][j] == 1)
                    waterqueue.push({i, j});
                else 
                    result[i][j] = -1;
            }
        }
        while (!waterqueue.empty()) {
            int x = waterqueue.front().first;
            int y = waterqueue.front().second;

            for (int i = 0; i < 4; i++) {
                int newx = x+dx[i];
                int newy = y+dy[i];

                if (newx < 0 || newx >= row || newy < 0 || newy >= col)  continue;
                if (result[newx][newy] >= 0)    continue;
                result[newx][newy] =result[x][y]+1;
                waterqueue.push({newx, newy});
            }
            waterqueue.pop();
        }
        return result;
    }
};

int main() {
    Solution solu;
    vector<vector<int>> iswater{{0,0,1},{1,0,0},{0,0,0}};
    vector<vector<int>> result = solu.highestPeak(iswater);

    for (auto& r : result) {
        for (int e : r)
            cout << e << " ";
        cout << "\n";
    }

    return 0;
}