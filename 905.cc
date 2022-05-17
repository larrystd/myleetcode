#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size()-1;

        while (left < right) {
            while (left < right && (nums[right] & 1 ==1))
                right--;
            while (left < right && (nums[left] & 1 ==0))
                left++;
            cout << right << " " << left << endl;
            swap(nums[left], nums[right]);
            cout << nums[0] << " " <<nums[1] << " " << nums[2] << " " << nums[3] << endl;
        }

        return nums;
    }
};