#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> arrmap;
        for (int e : arr) {
            arrmap[e] ++;
        }

        for (auto& p : arrmap) {
            if (p.second == 0)
                continue;
            if (p.first & 1)
                return false;
            if ((p.first < 0 && arrmap[p.first/2] <= 0) || (p.first >= 0 && arrmap[2*p.first]<=0)) {
                return false;
            }
            p.second--;
            p.first < 0 ? arrmap[p.first/2]-- : arrmap[2*p.first]--;
        }

        for (auto& p : arrmap) {
            if (p.second != 0)
                return false;
        }
        return true;

    }
};

int main() {
    Solution solu;

    vector<int> arr = {-5,-2};
    cout << solu.canReorderDoubled(arr) << "\n";

    return 0;
}

