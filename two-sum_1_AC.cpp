#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_to_index_map;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            auto complement = target - nums[i];
            auto it = num_to_index_map.find(complement);
            if (it != num_to_index_map.end()) {
                return {it->second, static_cast<int>(i)};
            }
            num_to_index_map.emplace(nums[i], static_cast<int>(i));
        }
        // As per typical LeetCode problem statement, a solution is always found.
        // Returning an empty vector or throwing an exception for the case where no solution is found.
        // To satisfy the compiler that all control paths return a value:
        return {}; // Or throw std::runtime_error("No two sum solution");
    }
};
