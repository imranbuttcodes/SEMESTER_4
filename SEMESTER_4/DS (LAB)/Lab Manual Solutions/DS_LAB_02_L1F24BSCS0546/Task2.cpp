#include <iostream>
using namespace std;


int BinarySearch(int arr[], int target, int n) {
	int st = 0, end = n - 1;
	while (st <= end)
	{
		int mid = st + (end - st) / 2;
		if (arr[mid] == target)		return mid;

		if (target < arr[mid]) {
			end = mid - 1;
		}
		else {
			st = mid + 1;
		}
	}
	return -1;
}

int main() {

	int arr[] = {1,2,3,4,5,6};
	int size = 6;
	int target = 4;
	cout << "Element to search (" << target << "):  Index Found: " << BinarySearch(arr, target, size) << endl;

}