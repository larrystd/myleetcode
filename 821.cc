
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int len = s.size();
        int left_idx = -len;
        int right_idx = 2*len;
        vector<int> result(len);

        for (int i = 0; i < len; i++) {
            if (s[i] == c)
                left_idx = i;
            
            result[i] = i - left_idx;
        }   

        for (int j = len-1; j >= 0; j--) {
            if (s[j] == c)
                right_idx = j;
            result[j] = min (result[j], right_idx - j);
        }

        return result;
    }
};

int main() {
    Solution solu;

    string s = "loveleetcode";
    char c = 'e';

    vector<int>&& ret = solu.shortestToChar(s, c);

    for (int e : ret) {
        cout << e << "\n";
    }

    return 0;
}