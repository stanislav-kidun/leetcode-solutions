// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include <vector>

class Solution {
    size_t Step(std::vector<int>::iterator& left_1, std::vector<int>::iterator& right_1, std::vector<int>::iterator& left_2, std::vector<int>::iterator& right_2, size_t& target_idx) {
        size_t size_1 = right_1 - left_1;

        auto res_1 = left_1 + ((size_1 - 1) / 2);
        auto res_2 = std::lower_bound(left_2, right_2, *res_1);
        size_t res_1_size = res_1 - left_1 + 1; 
        size_t res_2_size = res_2 - left_2; 

        if(res_1_size + res_2_size >= target_idx) {
            right_1 = res_1 + 1;
            right_2 = res_2;
        } else {
            left_1 = res_1 + 1;
            left_2 = res_2;
            target_idx -= res_1_size + res_2_size;
        }

        return target_idx;
    }

    int GetNext(std::vector<int>::iterator& left_1, std::vector<int>::iterator& right_1, std::vector<int>::iterator& left_2, std::vector<int>::iterator& right_2) {
        if(left_1 == right_1) {
            return *(left_2++);
        } else if(left_2 == right_2) {
            return *(left_1++);
        } else {
            if(*left_1 <= *left_2) {
                return *(left_1++);
            } else {
                return *(left_2++);
            }
        }
        return 0;
    }

public:
    double findMedianSortedArraysTargetIdx(std::vector<int>& nums1, std::vector<int>& nums2, size_t target_idx) {
        double result = 0;

        auto left_1 = nums1.begin();
        auto right_1 = nums1.end();
        auto left_2 = nums2.begin();
        auto right_2 = nums2.end();

        while(target_idx > 2) {
            size_t size_1 = right_1 - left_1;
            size_t size_2 = right_2 - left_2;
            if(size_1 >= size_2 ) {
                Step(left_1, right_1, left_2, right_2, target_idx);
            } else {
                Step(left_2, right_2, left_1, right_1, target_idx);
            }
        }

        if(target_idx > 1) {
            GetNext(left_1, right_1, left_2, right_2);
        }
        return GetNext(left_1, right_1, left_2, right_2);
    }

    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        double result = 0;

        size_t target = (nums1.size() + nums2.size()) / 2 + 1;

        result += findMedianSortedArraysTargetIdx(nums1, nums2, target);
        if((nums1.size() + nums2.size()) % 2 == 0) {
            result += findMedianSortedArraysTargetIdx(nums1, nums2, target - 1);
            result /= 2;
        }

        return result;
    }
};