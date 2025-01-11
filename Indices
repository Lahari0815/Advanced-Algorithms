#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; 

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Finding the complement that adds up to target

        if (numMap.count(complement)) {
            return {numMap[complement], i};
        }

        // If complement not found, add the number and its index to the map
        numMap[nums[i]] = i;
    }
    
    return {}; // if no solution found
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n < 2 || n > 104) {
        cout << "Invalid input: The number of elements must be between 2 and 104.\n";
        return 1;
    }

    vector<int> nums(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] < -109 || nums[i] > 109) {
            cout << "Invalid input: Array elements must be between -109 and 109.\n";
            return 1;
        }
    }

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    if (target < -109 || target > 109) {
        cout << "Invalid input: The target value must be between -109 and 109.\n";
        return 1;
    }

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found" << endl;
    }
    
    return 0;
}
