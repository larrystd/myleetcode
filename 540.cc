#include <vector>
#include <iostream>

using namespace std;

/*
假设只出现一次的元素位于下标x, 可以判断下标x的左边和右边都有偶数个元素, 数组长度为奇数。

同时, 对x左边的下标y, 如果nums[y] = nums[y+1], 则y为偶数(0,2,4...)
对x右边的下标z, 如果nums[z]=nums[z+1], 则z为奇数(7, 9, 11)
x 是相同元素开始下标奇偶性的分界

二分查找时对于mid下标, 如果mid是偶数, 比较nums[mid]和nums[mid+1]是否相等
如果mid是奇数, 比较nums[mid-1]和nums[mid]是否相等

如果相等, 说明x在mid右边, low=mid+1
如果不等, 说明x在mid左边(x也可以等于mid), high=mid

迭代到最后剩下的数就是所求的数
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int start = 0;
        int end = nums.size()-1;

        while (start < end) {
            int mid = (start + end) >> 1;
            if (mid & 1) {
                if (nums[mid] == nums[mid-1]) {
                    start = mid+1;
                }else {
                    end = mid;
                }
            }else {
                if (nums[mid] == nums[mid+1]) {
                    start = mid+1;
                }else {
                    end = mid;
                }
            }
        }

        return nums[start];
    }
};

int main() {
    vector<int> nums{1,1,2,3,3,4,4,8,8};
    Solution solu;
    cout << solu.singleNonDuplicate(nums) << "\n";

    return 0;
}