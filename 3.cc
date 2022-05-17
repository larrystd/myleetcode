#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> count_map;
        int left = 0, right = 0;
        int len = s.size();
        int result = 0;
        while (right < len) {
            while (left <= right && count_map[s[right]] != 0) {
                count_map[s[left]]--;
                left++;
            }
            result = max(result, right-left+1);
            count_map[s[right]] ++;
            right++;
        }

        return result;
    }
};

int main() {
    string s("pwwkew");
    Solution solu;

    cout << solu.lengthOfLongestSubstring(s) << "\n";

    return 0;
}