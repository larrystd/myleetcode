/*
442. 数组中重复的数据
给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。请你找出所有出现 两次 的整数，并以数组形式返回。

你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。

注意这里条件有个, nums的所有整数都在范围[1,n]内, 这样nums自身就构成了一个桶, 即可以通过nums[nums[i]]来记录。 
不使用额外空间, 但使用nums自己的空间是合适的
*/
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return vector<int>{};
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int num = abs(nums[i]);
            if (nums[num-1] > 0)
                nums[num-1] *= -1;
            else  
                result.push_back(num);
        }

        return result;
    }
};


int main() {
    Solution solu;
    vector<int> nums{0};

    vector<int>&& result = solu.findDuplicates(nums);
    for (int e : result) {
        cout << e << " ";
    }

    return 0;
}