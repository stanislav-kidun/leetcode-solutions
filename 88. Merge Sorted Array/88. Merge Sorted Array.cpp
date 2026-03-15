// https://leetcode.com/problems/merge-sorted-array/description/

#include <vector>

class Solution {
    std::vector<int> sorted;

    void Append(std::vector<int>& nums, size_t start, size_t size) {
        while(start < size) {
            sorted.push_back(nums[start]);
            ++start;
        }
    }

public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        size_t i = 0;
        size_t j = 0;
        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) {
                sorted.push_back(nums1[i]);
                ++i;
            } else {
                sorted.push_back(nums2[j]);
                ++j;
            }
        }

        Append(nums1, i, m);
        Append(nums2, j, n);

        for(size_t i = 0; i < n + m; ++i) {
            nums1[i] = sorted[i];
        }
    }
};