#include<iostream>
#include<ctime>

/*
merge - слияние
        i
1 3 5 6
        j
2 4 7 8
1 2 3 4 5 6 7 8

*/

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }
    while (i < leftSize) {
        arr[k++] = left[i++];
    }
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

void recursiveMergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (right + left) / 2;
    /*
    8 6 4 3 7 5 2 1
    
    8 6 4 3      7 5 2 1
    
    
    8 6   4 3


    8  6  4  3
    */
    recursiveMergeSort(arr, left, mid);
    recursiveMergeSort(arr, mid + 1, right);

    int leftLen = mid - left + 1;
    int* leftArr = new int[leftLen];
    for (int i = 0; i < leftLen; i++) {
        leftArr[i] = arr[left + i];
    }

    int rightLen = right - mid;
    int* rightArr = new int[rightLen];
    for (int i = 0; i < rightLen; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    merge(arr, leftArr, leftLen, rightArr, rightLen);
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

    recursiveMergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}