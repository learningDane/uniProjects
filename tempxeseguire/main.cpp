#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int> nums{3, 4, 10, 9};
    int target = 13;
    short int n = 0;
    int n1 = nums[n];
    int n2 = nums[n];
    int length = 0;
    for (int element: nums) {
        length++;
    }
    vector<int> result;

    while (nums[n1] + nums[n2] != target) {
        while (nums[n] >= target) {
            n++;
        }
        n1 = n;

        while (nums[n1] + nums[n] != target || n == length) {
            n++;
        }
        n2 = n;
    }

    result.push_back(n1);
    result.push_back(n2);
    n = 0;
    for (int element: result) {
        cout << result[n] << endl;
        n++;
    }
}