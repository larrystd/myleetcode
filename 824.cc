#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string toGoatLatin(string sentence) {
        string result;

        int left = 0,right = 0;
        int numwords = 0;
        while (right <= sentence.size()) {
            if (sentence[right] == ' ' || right == sentence.size()) {
                if (sentence[left] == 'a' || sentence[left] == 'e' || sentence[left] == 'i' || sentence[left] == 'o' ||sentence[left] == 'u' || sentence[left] == 'A' || sentence[left] == 'E' || sentence[left] == 'I' || sentence[left] == 'O' ||sentence[left] == 'U') {
                    result.append(sentence.substr(left, right-left));
                    
                }else {
                    result.append(sentence.substr(left + 1, right - left - 1));
                    result.push_back(sentence[left]);
                }
                numwords++;

                result.append("ma");
                result.insert(result.end(), numwords, 'a');

                if (right !=  sentence.size())
                    result.push_back(' ');

                right ++;
                left = right;
            }
            right ++;
        }

        return result;
    }
};

int main() {
    Solution solu;

    //string sentence = "The quick brown fox jumped over the lazy dog";
    char str[160];

    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    cin.getline(str, 160);
    string sentence(str);

    cout << solu.toGoatLatin(sentence) << "\n";

    return 0;
}