/*
1185 一周中的第几天
给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。

输入为三个整数：day、month 和 year，分别表示日、月、年。
您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}。

给出的日期一定是在 1971 到 2100 年之间的有效日期。
*/

class Solution {
public:
    string dayOfTheWeek(int d, int m, int y) {
        //蔡勒公式
        vector<int>benchmark = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        vector<string>week={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        y -= m < 3;
        return week[(y + y/4 - y/100 + y/400 + benchmark[m-1] + d) % 7];
    }
};
