#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> strmap{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    vector<string> letterCombinations(string digits) {
        string tempstr;
        dfs(digits, 0, tempstr);
        return result;
    }

    void dfs(const string& digits, int index, string& tempstr) {
        if (index == digits.size()) {
            result.push_back(tempstr);
            return;
        }
        string& str = strmap[digits[index]-'0'-2];
        for (char c : str) {
            tempstr.push_back(c);
            dfs(digits, index+1, tempstr);
            tempstr.pop_back();
        }
    }
};

int main() {
    Solution solu;
    auto&& result = solu.letterCombinations("");

    for (auto& e : result) {
        cout << e << " ";
    }

    return 0;
}