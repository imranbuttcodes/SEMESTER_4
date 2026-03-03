#include <iostream>
using namespace std;


void SelectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		
		int smallestIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[smallestIndex]) {
				smallestIndex = j;
			}
		}
		swap(arr[smallestIndex], arr[i]);

	}
	cout << "Array Sorted!" << endl;
	
}

int main() {

	int arr[] = {1,5,2,3,6,4};
	int size = 6;
	
	cout << "Before Sorting...\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;	
	SelectionSort(arr, size);

	cout << "After Sorting...\n";

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}

}