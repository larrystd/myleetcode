// leetcode 71 简化路径

/*
给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为更加简洁的规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。任意多个连续的斜杠（即，'//'）都被视为单个斜杠 '/' 。 对于此问题，任何其他格式的点（例如，'...'）均被视为文件/目录名称。

请注意，返回的 规范路径 必须遵循下述格式：

始终以斜杠 '/' 开头。
两个目录名之间必须只有一个斜杠 '/' 。
最后一个目录名（如果存在）不能 以 '/' 结尾。
此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
返回简化后得到的 规范路径 。

输入：path = "/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。 

用栈

res = []
把/ 分割成几块, 遍历
如果是 . 或者 空字符串 则跳过
如果是.. 说明需要返回上一级，即弹出一个文件名，也就是res.pop()但是这里有一个细节需要注意，只有res非空的时候才能弹出，否则对于测试用例 '/../'不能通过
如果是普通的文件名，则加入res.append()
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> splits;
        int startpos = 0;
        int splitpos = path.find('/', startpos);
        while (splitpos != path.npos) {
            splits.push_back(path.substr(startpos, splitpos-startpos));
            startpos = splitpos+1;
            splitpos = path.find('/', startpos);
        }
        if (startpos != path.npos)
            splits.push_back(path.substr(startpos));

        vector<string> processed;
        for (int i = 0; i < splits.size(); i++) {
            if (splits[i] == "." || splits[i] == "") {
                continue;
            }
            if (splits[i] == ".." ) {
                if (processed.size() >= 1) 
                    processed.pop_back();
                continue;
            }
            processed.push_back(splits[i]);
        }

        string result("");
        for (int i = 0; i < processed.size(); i++) {
            result += "/";
            result += processed[i];
        }
        if (result == "")
            result += "/";
        return result;
    }
};

int main() {
    string path = "/home//foo/";
    Solution solu;
    cout << solu.simplifyPath(path) << "\n";
    return 0;
}
