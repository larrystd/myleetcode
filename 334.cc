#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        int i = 0, j = 1, k = 2;
        int min_num , max_num, middle_num;
        while (k < nums.size()) {
            if (nums[i] < nums[j]&& nums[j] < nums[k]) {
                return true;
            }
            else if (nums[j] <= nums[i]&& nums[i] < nums[k]) {
                i = j;
                j = i+1;
                k = j+1;
            }
            else if (nums[k] <= nums[j]&& nums[j] <= nums[i]) {
                i = k;
                j = i+1;
                k = j+1;
            }
            else if (nums[j] < nums[k]&& nums[k] <= nums[i]) {
                i = j;
                j = i+1;
                k = j+1;
            }
            else if (nums[i] < nums[j]) {
                k++;
            }
            else if (nums[j] == nums[i]) {
                i = k;
                j = i+1;
                k = j+1;
            }
        }

        return false;

    }
};

int main() {
    vector<int> nums{20,100,10,12,5,13};

    Solution solu;

    cout << solu.increasingTriplet(nums) << "\n";

    return 0;
}