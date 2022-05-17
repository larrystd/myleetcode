#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int len = s.size();
        int partsize = 2*numRows-2;

        string result;
        int pos = 0;

        for (int row = 0; row < numRows; row++) {
            pos = row;
            while (pos < len) {
                result.push_back(s[pos]);
                if (numRows != 2 && row != 0 && row != numRows-1) {
                    if (pos+partsize-2*row >= len)
                        break;
                    result.push_back(s[pos+partsize-2*row]);
                }
                pos += partsize;
            }
        }

        return result;
        
    }
};

int main() {
    Solution solu;

    string s("PASD");
    cout << solu.convert(s, 2) << endl;

    return 0;
}