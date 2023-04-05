#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <windows.h> // time()
#include <math.h>    // библиотека матеши
#include <time.h>
using namespace std;

const int size = 20;
const int length = 20;
const int mmr = 100;

void _binary(int arr[], int length, int key)
{
	bool zone = false;
	int l = 0, r = 8, mid;
	while ((l <= r) && (zone != true))
	{
		mid = (l + r) / 2;
		if (arr[mid] == key) zone = true;
		if (arr[mid] > key) r = mid - 1;
		else l = mid + 1;
	}
	if (zone)
		cout << "index el: " << key << " == " << mid << endl;
	else
		cout << "None" << endl;
}

template <class T>
void BubbleSort(T arr[], int length, int i) {
	switch (i) {
	case 0:

		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length - 1; j++)
			{
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
				}
			}
		}

		break;
	case 1:
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length - 1; j++)
			{
				if (arr[j] < arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
				}
			}
		}
		break;
	default:
		cout << "Error";
		break;
	}
}

void Sort(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == arr[i + 1]) {
			arr[i + 1] = 1 + rand() % 20;

			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < length - 1; j++)
				{
					if (arr[j] > arr[j + 1]) {
						swap(arr[j], arr[j + 1]);
					}
				}
			}

			return Sort(arr, length);
		}
	}
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	//system("color B5");

	bool end = false;
	int arr[::size] = {};

	for (int i = 0; i < ::size; i++) {
		arr[i] = 1 + rand() % 20;
	}
	cout << "Изначальный массив: ";
	for (int i = 0; i < ::size; i++) {
		cout << arr[i] << " ";
	}

	BubbleSort(arr, ::size, 0);
	Sort(arr, ::size);
	cout << "\nBubbleSort: ";
	for (int i = 0; i < ::size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\nBinary: "; _binary(arr, ::size, 9);

}
