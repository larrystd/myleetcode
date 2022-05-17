#include <vector>
#include <iostream>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> memory;
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sumnums = accumulate(piles.begin(), piles.end(), 0);
        memory.assign( n, vector<int>(n, -1));

        int alicegain = dfs(piles, 0, piles.size()-1);

        return alicegain > sumnums - alicegain;
    }

    int dfs(vector<int>& piles, int left, int right) {

        if (left == right) {
            return piles[left];
        }
        if (memory[left][right] != -1)
            return memory[left][right];

        return memory[left][right] = max (piles[left] + dfs(piles, left + 1, right), piles[right] + dfs(piles, left, right-1));

    }
};

int main () {
    Solution solu;
    vector<int> nums = {7,7,12,16,41,48,41,48,11,9,34,2,44,30,27,12,11,39,31,8,23,11,47,25,15,23,4,17,11,50,16,50,38,34,48,27,16,24,22,48,50,10,26,27,9,43,13,42,46,24};
    cout << solu.stoneGame(nums) << "\n";

    return 0;
}