#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int left = mean*(m+n) - accumulate(rolls.begin(), rolls.end(), 0);
        if (left > n*6)
            return vector<int>();
        vector<int> result;
        dfs(n, left, result);
        return result;
    }

    bool dfs(int k, int left, vector<int>& temp) {
        if (left < k)
            return false;
        if (k == 0 && left == 0) {
            return true;
        }

        if (k == 0) {
            return false;
        }
        for (int i = 6; i >= 1; i--) {
            temp.push_back(i);
            if (dfs(k-1, left-i, temp))
                return true;
            temp.pop_back();
        }
        return false;
    }
};

int main() {
    vector<int> rolls={4,5,6,2,3,6,5,4,6,4,5,1,6,3,1,4,5,5,3,2,3,5,3,2,1,5,4,3,5,1,5};
    int mean = 4;
    int n = 40;
    Solution solu;
    vector<int> ret = solu.missingRolls(rolls, mean, n);

    for (int e : ret) {
        cout << e << "\n";
    }

    cout << 1/2 << endl;
    return 0;
}