#include<iostream>
#include<ctime>

/*
Zero
One
Many
*/
/*
pivot = 5
		  j
				  i
8 4 9 6 7 3 2 1 5
4 8 9 6 7 3 2 1 5
4 3 9 6 7 8 2 1 5
4 3 2 1 7 8 9 6 5
4 3 2 1 5 8 9 6 7
*/
/*
pivot = 9
              j
                i
8 4 9 6 7 3 2 1 5
8 4 6 9 7 3 2 1 5
8 4 6 7 9 3 2 1 5
8 4 6 7 3 9 2 1 5
8 4 6 7 3 2 9 1 5
8 4 6 7 3 2 1 9 5
8 4 6 7 3 2 1 5 9
*/
int partition(int arr[], int low, int high, int pivot) {
	int i = low;
	int j = low;
	while (i <= high) {
		if (arr[i] >= pivot) {
			i++;
		}
		else {
			std::swap(arr[i], arr[j]);
			i++;
			j++;
		}
	}
	return j - 1;
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[high];
		int pos = partition(arr, low, high, pivot);
		quickSort(arr, low, pos - 1);
		quickSort(arr, pos + 1, high);
	}
}

int main(int argc, char* argv[])
{
	srand(time(nullptr));
	const int n = 10;
	int arr[n]{ 0 };
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 90 + 10;
	}

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	return EXIT_SUCCESS;
}