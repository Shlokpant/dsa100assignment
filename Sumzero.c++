// Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the count of subarrays having sum zero

// Example:
// Input:
// 6
// 1 -1 2 -2 3 -3

// Output:
// 6

// Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.

// code

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> mp;

    int prefixSum = 0;
    int count = 0;

    // Prefix sum 0 occurs once before starting
    mp[0] = 1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (mp.find(prefixSum) != mp.end())
            count += mp[prefixSum];

        mp[prefixSum]++;
    }

    cout << count << endl;

    return 0;
}