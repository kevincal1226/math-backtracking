#include <algorithm>
#include <iostream>
#include <vector>

bool backtrack(std::vector<int> &nums, std::vector<char> &operations, int target, int current, size_t index) {
    if (index == nums.size()) {
        return target == current;
    }
    operations.emplace_back('+');
    if (backtrack(nums, operations, target, current + nums[index], index + 1)) {
        return true;
    };
    operations.back() = '-';
    if (backtrack(nums, operations, target, current - nums[index], index + 1)) {
        return true;
    };
    operations.back() = '*';
    if (backtrack(nums, operations, target, current * nums[index], index + 1)) {
        return true;
    };
    operations.back() = '/';
    if (nums[index] != 0 && current % nums[index] == 0 &&
        backtrack(nums, operations, target, current / nums[index], index + 1)) {
        return true;
    };
    operations.pop_back();
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
    std::cout << "Found answer: ";
    for (size_t i = 0; i < operations.size(); ++i) {
        std::cout << nums[i] << ' ' << operations[i] << ' ';
    }
    std::cout << nums.back() << " = " << target << '\n';
    return 0;
}
