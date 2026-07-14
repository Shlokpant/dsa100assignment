// Problem: Given an array of integers, rotate the array to the right by k positions.

// Input:
// - First line: integer n
// - Second line: n integers
// - Third line: integer k

// Output:
// - Print the rotated array

// Example:
// Input:
// 5
// 1 2 3 4 5
// 2

// Output:
// 4 5 1 2 3



#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    k = k % n;  // Handle cases where k > n

    // Reverse the entire array
    reverse(arr, arr + n);

    // Reverse first k elements
    reverse(arr, arr + k);

    // Reverse remaining elements
    reverse(arr + k, arr + n);

    // Print rotated array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}