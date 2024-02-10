#include <iostream>

using namespace std;

constexpr unsigned MAX_LENGTH = 1024 + 1;

void input(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
}

void mySwap(int& num1, int& num2) {
	int sw = num1;
	num1 = num2;
	num2 = sw;
}

int removeZeros(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		while (size != 0 && arr[i] == 0) {
			mySwap(arr[i], arr[size - 1]);
			size--;
		}
	}
	return size;
}

bool isValidIndex(int arr[],int idx, int size) {
	return arr[idx] >= 0 && arr[idx] < size;
}

void adjustElemnt(int arr[], int idx, int size) {
	while (isValidIndex(arr, idx, size) && arr[idx] - 1 != idx && arr[idx] != arr[arr[idx] - 1]) {
		mySwap(arr[idx], arr[arr[idx] - 1]);
	}
}

int leastPositiveMissing(int arr[], int size){
	input(arr, size);
	size = removeZeros(arr, size);

	for (int i = 0; i < size; i++) {
		adjustElemnt(arr, i, size);
	}

	for (int i = 0; i < size; i++) {
		if (arr[i] != i + 1) {
			return i + 1;
		}
	}
	return size + 1;
}

int main()
{
    unsigned n = 0;
    cin >> n;

    int arr[MAX_LENGTH] = {0};
    leastPositiveMissing(arr, n);
}