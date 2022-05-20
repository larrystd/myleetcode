#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int size = order.size();
        vector<char> orderchar(size);
        for (int i = 0; i < size; i++) {
            orderchar[order[i] - 'a'] = i;
        }

        int part = 0;
        int pos = 0;
        while() {

            for (int i = 0; i < words.size()-1; i++) {
                if (orderchar[words[i][pos]] > orderchar[words[i+1][pos]])
                    return false; 
            }
        }
    }
};