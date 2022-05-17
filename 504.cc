#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        string result("");
        if (num < 0) {
            result.push_back('-');
            num = -num;
        }

        int base = 1;
        while (num >= base*7) {
            base *= 7;
        }


        while (base){
            result.push_back(num / base +'0');
            num %= base;
            base /=7;
        }
        return result;
    }
};

int main() {
    Solution solu;

    cout << solu.convertToBase7(101) << "\n";

    return 0;
}