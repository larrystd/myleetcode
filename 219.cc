#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map_nums;

        for (int i = 0; i < nums.size(); i++) {
            if (!map_nums.count(nums[i]))
                map_nums[nums[i]] = i;
            else {
                if (abs(map_nums[nums[i]] - i) <= k)
                    return true;
                map_nums[nums[i]] = i;
            }
        }
        return false;
    }
};