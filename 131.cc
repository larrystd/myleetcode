#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> countmap;
    vector<vector<string>> result;
    vector<vector<string>> partition(string s) {
        vector<string> tempres;
        countmap.assign(s.size(), vector<int>(s.size()));
        trackback(s, 0, tempres);

        return result;
    }

    void trackback(const string& s, int start, vector<string>& tempres) {
        if (start == s.size()) {
            result.push_back(tempres);
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (isTarget(s, start, end) == 1) {
                string temp = s.substr(start, end-start+1);
                tempres.emplace_back(std::move(temp));
                trackback(s, end+1, tempres);
                tempres.pop_back();
            }
        }
    }

    int isTarget(const string& s, int i, int j) {
        if (i == j-1 && s[i] == s[j])
            return 1;
        if (i == j)
            return 1;
        if (countmap[i][j] != 0)
            return countmap[i][j];
        countmap[i][j] = s[i] == s[j] ? isTarget(s, i+1, j-1):-1;
        return countmap[i][j];
    }
};

int main() {
    Solution solu;
    string s("aaaa");
    auto&& result = solu.partition(s);

    for (auto& vec : result) {
        for (string& s : vec) {
            cout << s << " ";
        }
        cout << "\n";
    }
    
    return 0;
}