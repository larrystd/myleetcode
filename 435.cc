/* 435. 无重叠区间
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。

当按照区间右边界排序后, 移除较大的右边界总不会错， 例如[1,2],[1,3],[4,5] 移除[1,3]总不会错, 因为3>2, [1,3]能行的[1,2]也一定能行
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& lhs, vector<int>&rhs) {
            return  lhs[1] < rhs[1];
        });

        int prev = 0;
        int result = 0;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= intervals[prev][1]) {
                prev = i;
            }else {
                result++;
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> intervals{{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};

    Solution solu;
    cout << solu.eraseOverlapIntervals(intervals) << "\n";

    return 0;
}
