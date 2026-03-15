// https://leetcode.com/problems/merge-sorted-array/description/

#include <vector>
#include <stdio.h>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        ssize_t i = m - 1;
        ssize_t j = n - 1;
        ssize_t pos = n + m - 1;
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[pos] = nums1[i];
                --i;
            } else {
                nums1[pos] = nums2[j];
                --j;
            }
            --pos;
        }

        while (i >= 0) {
            nums1[pos] = nums1[i];
            --i;
            --pos;
        }

        while (j >= 0) {
            nums1[pos] = nums2[j];
            --j;
            --pos;
        }
    }
};