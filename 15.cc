#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        int first, second, third;

        for (first = 0; first < nums.size(); first++) {
            if (first >0 && nums[first] == nums[first-1])
                continue;
            third = nums.size()-1;
            int target = -nums[first];
            for (second = first + 1; second < nums.size(); second++) {
                if (second > first+1 && nums[second] == nums[second-1])
                    continue;
                while (second < third && nums[second] + nums[third] > target)
                    third--;
                if (second == third)
                    break;
                if (nums[second] + nums[third] == target)
                    result.push_back({nums[first], nums[second], nums[third]});
            }
        }

        return result;
    }
};