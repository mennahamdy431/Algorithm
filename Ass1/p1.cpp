#include <iostream>
using namespace std;

int insertionSort(int data[], int n) {
	int counter = 0;
	for (int i = 1, j; i < n; i++) {
		int m = data[i];
		for (j = i; j > 0 && m < data[j - 1]; j--) {
			data[j] = data[j - 1];
			counter++;
		}
		data[j] = m;
	}
	return counter;
}


int main()
{
	int arr[5];
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	cout << insertionSort(arr, 5);


}

