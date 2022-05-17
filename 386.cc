#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int curnumber = 1;
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            result[i] = curnumber;

            if (curnumber* 10 <= n) {
                curnumber *= 10;
            }else {
                while (curnumber % 10 == 9 || curnumber == n) {
                    curnumber /= 10;
                }
                curnumber ++;
            }
        }

        return result;
    }
};

int main() {
    Solution solu;

    vector<int> ret = solu.lexicalOrder(133);

    for (int e : ret) {
        cout << e <<"\n";
    }

    // cin >

    return 0;
}