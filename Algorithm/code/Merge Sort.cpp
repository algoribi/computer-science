#include <iostream>
#define size 8

using namespace std;

int sorted[size];

void merge(int a[], int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            sorted[k] = a[i];
            i++;
        } else {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }

    if (i > mid) {
        for (j; j <= end; j++) {
            sorted[k] = a[j];
            k++;
        }
    } else {
        for (i; i <= mid; i++) {
            sorted[k] = a[i];
            k++;
        }
    }

    for (int l = start; l <= end; l++) {
        a[l] = sorted[l];
    }
}

void mergeSort(int a[], int start, int end) {
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);
    merge(a, start, mid, end);
}

int main() {
    int arr[size] = {7, 6, 2, 8, 3, 5, 4, 1};
    mergeSort(arr, 0, size - 1);
    //출력
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}