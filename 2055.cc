#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int len = s.size();
        vector<int> presum(len); // 前缀和, 记录到i为止(包含)的盘子数量
        
        for (int i = 0, sum = 0; i < len; i++) {
            if (s[i] == '*')
                sum++;
            presum[i] = sum;
        }

        vector<int> left_pos(len);   // 索引i左侧的蜡烛位置
        for (int i = 0, pos=-1; i < len; i++) {
            if (s[i] == '|')
                pos = i;
            left_pos[i] = pos;
        }

        vector<int> right_pos(len);
        for (int i = len-1, pos = len-1; i >= 0; i--) { // 索引i右侧的蜡烛位置
            if (s[i] == '|')
                pos = i;
            right_pos[i] = pos;
        }

        vector<int> result;
        for (auto& query : queries) {
            int x = right_pos[query[0]], y = left_pos[query[1]];

            result.push_back(x == -1 || y == -1 || x>=y ? 0 : presum[y]-presum[x]);
        }
        return result;
    }

    vector<int> platesBetweenCandlesV2(string s, vector<vector<int>>& queries) {
                int len = s.size();
        vector<int> presum(len); // 前缀和, 记录到i为止(包含)的盘子数量
        
        for (int i = 0, sum = 0; i < len; i++) {
            if (s[i] == '*')
                sum++;
            presum[i] = sum;
        }

        vector<int> candlepos;

        for (int i = 0; i < len; i++) {
            if (s[i] == '|')
                candlepos.push_back(i);
        }

        vector<int> result;
        for (auto& query : queries) {
            
            int x = query[0], y = query[1];
            int left = 0, right = candlepos.size()-1;
            
            while (left <= right) {
                int mid = left + (right-left)/2;
                if (candlepos[mid] < x)
                    left = mid+1;
                else  
                    right = mid-1;
            }
            x = candlepos[left];
            left = 0, right = candlepos.size()-1;
            while (left <= right) {
                int mid = left + (right-left)/2;
                if (candlepos[mid] <= y)
                    left = mid+1;
                else  
                    right = mid-1;
            }
            y = candlepos[right];
            result.push_back(x == -1 || y == -1 || x>=y ? 0 : presum[y]-presum[x]);
        }
        return result;
    }
};

int main() {
    Solution solu;

    string s = "**";
    vector<vector<int>> queries = {{2,2}};

    auto&& result = solu.platesBetweenCandlesV2(s, queries);

    for (auto& e : result) {
        cout << e << "\n";
    }

    return 0;
}