#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            result += numbersWithUniqueDigits(i);
        }

        int result2[] = {1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851};

        return result;
    }

    int numbersWithUniqueDigits (int n) {
        if (n == 1)
            return 10;
        vector<int> visited(10);    // 每个数字是否访问到
        int count = 0;
        for (int i = 1; i <= 9; i++) {
            visited[i] = 1;
            dfs(visited, n-1, count);
            visited[i] = 0;
        }

        return count;
    }

    void dfs(vector<int>& visited, int left, int& count) {
        if (left == 0) {
            count ++;
            return;
        }
        
        for (int i = 0; i <= 9; i++) {
            if (visited[i])
                continue;
            visited[i] = 1;
            dfs(visited, left-1, count);
            visited[i] = 0;
        }
    }
};

int main() {
    Solution solu;

    for (int i = 1; i <= 8; i++) {
        cout << solu.countNumbersWithUniqueDigits(i) << "\n";
    }

    return 0;
}