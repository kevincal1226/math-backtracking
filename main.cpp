#include <algorithm>
#include <iostream>
#include <vector>

bool backtrack(std::vector<int> &nums, std::vector<char> &operations, int target, int current, size_t index) {
    if (index == nums.size()) {
        return target == current;
    }
    return false;
}

int main() {
    std::vector<int> nums;
    int target, temp;
    std::cin >> target;
    while (std::cin >> temp) {
        nums.emplace_back(temp);
    }
    bool foundAnswer = false;
    std::vector<char> operations;
    do {
        foundAnswer = backtrack(nums, operations, target, nums[0], 1);
    } while (!foundAnswer && std::next_permutation(nums.begin(), nums.end()));
    if (!foundAnswer) {
        std::cout << "No possible permutation could be found to create target value " << target << ".\n";
        return 0;
    }
    return 0;
}
