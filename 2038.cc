#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int constantA = 0;
        int constantB = 0;

        int deletenumA = 0;
        int deletenumB = 0;

        for (int i = 0; i < colors.size(); i++) {
            if (colors[i] == 'A') {
                constantA++;
                constantB = 0;
            }else {
                constantB++;
                constantA = 0;
            }
            if (constantA >= 3) {
                deletenumA++;
            }
            if (constantB >= 3) {
                deletenumB++;
            }
        }
        return deletenumA > deletenumB;

    }
};

int main() {
    Solution solu;

    cout << solu.winnerOfGame("AA") <<endl;

    return 0;
}