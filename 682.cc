#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        list<int> opslist;

        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == "+") {
                int tail = opslist.back();
                list<int>::iterator iter = opslist.end();
                 std::advance(iter, -2);
                int secondtail = *iter;
                cout << secondtail << endl;
                opslist.push_back(tail + secondtail);
            }else if (ops[i] == "D") {
                opslist.push_back(opslist.back()*2);
            }else if (ops[i] == "C") {
                opslist.pop_back();
            }else {
                opslist.push_back(atoi(ops[i].c_str()));
            }
        }

        return accumulate(opslist.begin(), opslist.end(), 0);
    }
};

int main() {
    vector<string> input = {"5","2","C","D","+"};

    Solution solu;
    cout << solu.calPoints(input) << "\n";

    return 0;
}