#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> grayCode(int n) {
        if (n == 0) 
            return vector<int>{0};
        vector<int> result = {0, 1};

        for (int i = 1; i < n; i++) {
            int n = result.size();
            for (int j = n-1; j >= 0; j--) {
                result.push_back(result[j]+(1<<i));
            }
        }

        return result;
    }
};

int main() {
    vector<int> result = Solution::grayCode(2);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}