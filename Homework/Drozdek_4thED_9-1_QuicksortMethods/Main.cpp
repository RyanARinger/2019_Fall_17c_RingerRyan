/*
 * File:		main.cpp
 * Author:		Ryan Ringer
 * Purpose:		testing the methods for selecting bounds in quicksort
 * Created on:	November 20th, 2019
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

void generateArray(int*, int);
void generateArray(int*, int*, int);
void printArray(int*, int);
void medianQuicksort(int*, int);
void medianQuicksort(int*, int, int);
void randomIndexQuicksort(int*, int);
void randomIndexQuicksort(int*, int, int);
void shuffle(int*, int);
void swap(int*, int, int);
void destroy(int*);

///////////////////////////////////////////////////////////////////////////////
/*
 * Using an index in the middle of the array to be sorted provedto be
 * consistently more efficient. On tests with one hundred elements showed a
 * difference of an average of five microseconds and in tests with ten
 * thousand elements showed an average time difference of almost a three
 * hundred and fifty microseconds. This proves that a bound that evenly splits
 * the array to be sorted will almost always be more efficient than a
 * randomized point.
 */
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {
	// Seed random number or initialize scanner
	srand(static_cast<unsigned int>(time(0)));

	// Constant Variables
	const int SIZE = 1000;

	// Declare all Variables Here
	//int arr[SIZE];
	//int* arr = new int[SIZE];
	int* arr1 = new int[SIZE];
	int* arr2 = new int[SIZE];


	// Input or initialize values Here
	generateArray(arr1, arr2, SIZE);
	cout << "Original order of contents of arrays: " << endl << endl;
	printArray(arr1, SIZE);

	// Process/Calculations Here

	auto start = high_resolution_clock::now();
	medianQuicksort(arr1, SIZE);
	auto stop = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop - start);

	//shuffle(arr, SIZE);
	start = high_resolution_clock::now();
	randomIndexQuicksort(arr2, SIZE);
	stop = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop - start);

	// Output Located Here
	cout << "Median Method result:" << endl << endl;
	printArray(arr1, SIZE);
	cout << "Random Index Method result:" << endl << endl;
	printArray(arr2, SIZE);

	cout << "Median Method Took " << duration1.count() << " microseconds" << endl << endl;
	cout << "Random Index Method for bound selection took " << duration2.count() 
		 << " microseconds" << endl;

	// Exit
	destroy(arr1);
	destroy(arr2);
	return 0;
}

void generateArray(int* arr, int sz) {
	for (int i = 0; i < sz; i++) {
		arr[i] = rand() % 1000;
		//arr[i] = i;
	}
}
void generateArray(int* arr1, int* arr2, int sz) {
	for (int i = 0; i < sz; i++) {
		arr1[i] = rand() % 1000;
		arr2[i] = arr1[i];
	}
}

void printArray(int* arr, int sz) {
	for (int i = 0; i < sz; i++) {
		cout << arr[i] << " ";
		if (i % 10 == 9 && i != 0) {
			cout << endl;
		}
	}
	cout << endl << endl;
}

void medianQuicksort(int* arr, int sz) {
	if (sz <= 1) {
		return;
	}
	int max = 0;
	for (int i = 0; i < sz; i++) {
		if (arr[max] < arr[i]) {
			max = i;
		}
	}
	swap(arr[max], arr[sz-1]);
	medianQuicksort(arr, 0, sz - 2);

}

void medianQuicksort(int* arr, int first, int last) {
	int low = first + 1;
	int high = last;
	swap(arr[first], arr[(first + last)/2]);
	int b = arr[first];
	while (low <= high) {
		while (arr[low] < b) {
			low++;
		}
		while (arr[high] > b) {
			high--;
		}
		if (low < high) {
			swap(arr[low++], arr[high--]);
		}
		else {
			low++;
		}
	
	}
	swap(arr[high], arr[first]);
	if (first < high - 1) {
		medianQuicksort(arr, first, high - 1);
	}
	if (high + 1 < last) {
		medianQuicksort(arr, high + 1, last);
	}
}

void randomIndexQuicksort(int* arr, int sz) {
	if (sz <= 1) {
		return;
	}
	int max = 0;
	for (int i = 0; i < sz; i++) {
		if (arr[max] < arr[i]) {
			max = i;
		}
	}
	swap(arr[max], arr[sz - 1]);
	randomIndexQuicksort(arr, 0, sz - 2);

}

void randomIndexQuicksort(int* arr, int first, int last) {
	int low = first + 1;
	int high = last;
	swap(arr[first], arr[((rand()%(last-first))+first)]);
	int b = arr[first];
	while (low <= high) {
		while (arr[low] < b) {
			low++;
		}
		while (arr[high] > b) {
			high--;
		}
		if (low < high) {
			swap(arr[low++], arr[high--]);
		}
		else {
			low++;
		}

	}
	swap(arr[high], arr[first]);
	if (first < high - 1) {
		randomIndexQuicksort(arr, first, high - 1);
	}
	if (high + 1 < last) {
		randomIndexQuicksort(arr, high + 1, last);
	}
}

void shuffle(int* arr, int sz) {
	int str;
	int j;
	for (int i = 0; i < sz; i++) {
		j = rand() % sz;
		str = arr[j];
		arr[j] = arr[i];
		arr[i] = arr[j];
	}
}

void swap(int* arr, int one, int two) {
	int temp = arr[one];
	arr[one] = arr[two];
	arr[two] = temp;
}

void destroy(int* arr) {
	delete[] arr;
}