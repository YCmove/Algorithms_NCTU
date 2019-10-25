#include <iostream>
using namespace std;

// Return true if there exists a subarray of array[0..n] with given sum
bool subsetSum(int arr[], int n, int sum)
{
	// return true if sum becomes 0 (subset found)
	if (sum == 0)
		return true;

	// base case: no items left or sum becomes negative
	if (n < 0 || sum < 0)
		return false;

	// Case 1. include current item in the subset (arr[n]) and recur
	// for remaining items (n - 1) with remaining sum (sum - arr[n])
	bool include = subsetSum(arr, n - 1, sum - arr[n]);

	// Case 2. exclude current item n from subset and recur for
	// remaining items (n - 1)
	bool exclude = subsetSum(arr, n - 1, sum);

	// return true if we can get subset by including or excluding the
	// current item
	return include || exclude;
}

// Subset Sum Problem
int main()
{
	// Input: set of items and a sum
	int arr[] = { 7, 3, 2, 5, 8 };
	int sum = 14;

	// number of items
	int n = sizeof(arr) / sizeof(arr[0]);

	if (subsetSum(arr, n - 1, sum))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}