#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool oneEditAway(string first, string second) {
        int sizefirst = first.size();
        int sizesecond = second.size();

        if (sizefirst - sizesecond >= 2 || sizefirst - sizesecond <= -2)
            return false;

        if (sizefirst == sizesecond) {
            int p1 = 0, p2 = 0;
            bool isspan = false;
            while (p1 < sizefirst && p2 < sizesecond) {
                while (p1 < sizefirst && p2 < sizesecond && first[p1] == second[p2]) {
                    p1++;
                    p2++;
                }
                if (isspan)
                    break;
                p1++;
                p2++;
                isspan = true;
            }
            return p1 == sizefirst && p2 == sizesecond;
        }
        int p1 = 0, p2 = 0;
        bool isspan = false;
        while (p1 < sizefirst && p2 < sizesecond) {
            while (p1 < sizefirst && p2 < sizesecond && first[p1] == second[p2]) {
                p1++;
                p2++;
            }
            if (isspan)
                break;
            if (sizefirst > sizesecond)
                p1++;
            else 
                p2++;
            isspan = true;
        }

        return p1 == sizefirst && p2 == sizesecond;
    }
};

int main() {
    string first = "pae";
    string second = "ple";

    Solution solu;

    cout << solu.oneEditAway(first, second) << "\n";

    return 0;
}