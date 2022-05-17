#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {

        unordered_set<int> index_freq;
        int freq = 0;
        vector<int> result;

        if (time == 0) {
            for (int i = 0; i < security.size(); i++) {
                result.push_back(i);
            }
            return result;
        }

        freq = 1;
        for (int i = 1; i < security.size()-1; i++) {

            if (security[i] <= security[i-1]) {
                freq++;
            }else {
                freq = 1;
            }
            if (freq >= time+1) 
                index_freq.insert(i);
        }

        freq=1;
        for (int i = security.size()-2; i >0; i--) {
            if (security[i] <= security[i+1]) {
                freq++;
            }else {
                freq = 1;
            }
            if (freq >= time+1 && index_freq.count(i)) 
                result.push_back(i);
        }

        return result;
    }
};

int main() {
    Solution solu;
    vector<int> nums{5,3,3,3,5,6,2};
    vector<int> result = solu.goodDaysToRobBank(nums, 2);

    for (int e : result) {
        cout << e << "\n";
    }

    return 0;
}