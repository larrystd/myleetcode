#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> result;
        map<string, int> word_map;
        int start = 0;
        int end = s1.find(' ',start);
        while (end != s1.npos) {
            word_map[s1.substr(start, end-start)]++;
            start = end+1;
            end = s1.find(' ',start);
        }

        word_map[s1.substr(start, s1.npos-start)]++;

        start = 0;
        end = s2.find(' ',start);
        while (end != s2.npos) {
            word_map[s2.substr(start, end-start)]++;

            start = end+1;
            end = s2.find(' ',start);
        }
        word_map[s2.substr(start, s2.npos-start)]++;

        for (auto& p : word_map) {
            if (p.second == 1)
                result.push_back(p.first);
        }

        return result; 
    }
};

int main() {
    Solution solu;
    string s1 = "apple apple";
    string s2 = "this apple is sour";
    vector<string> result=solu.uncommonFromSentences(s1,s2);
    for (string& s : result) {
        cout << s << "\n";
    }

    return 0;
}