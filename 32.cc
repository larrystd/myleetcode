#include <string>
#include <iostream>
#include <list>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        list<char> strlist;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') 
                strlist.push_back(s[i]);
            else {
                int templength = 0;
                char top = strlist.back();
                while (top == '(') {
                    strlist.pop_back();
                    templength++;
                    top = strlist.back();
                }

            }
        }
    }
};