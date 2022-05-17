#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        bool isleft = target >= nums[0];
        int len = nums.size();
        int left = 0, right =len-1;

        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target)
                return mid;
            if (isleft) {
                if (nums[mid] < target && nums[mid] >= nums[0])
                    left = mid+1;
                else  
                    right = mid-1;
            }else {
                if (nums[mid] > target && nums[mid] <= nums[len-1])
                    right = mid-1;
                else  
                    left = mid+1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solu;
    vector<int> nums{4,5,6,7,0,1,2};

    cout << solu.search(nums, -2) << endl;

    return 0;
}