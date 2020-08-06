#include <iostream>
#include <vector>

using namespace std;

vector<int> arr = {2, 8, 1, 3, 6, 4, 7, 5, 9};

void quickSort(int start, int end) {
    if (start >= end)
        return;
    int i = start + 1, j = end;
    while (i <= j) {
        while (i <= end && arr[i] <= arr[start]) {
            i++;
        }
        while (j > start && arr[j] >= arr[start]) {
            j--;
        }
        if (i > j) {
            int temp = arr[j];
            arr[j] = arr[start];
            arr[start] = temp;
        } else {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    quickSort(start, j - 1);
    quickSort(j + 1, end);
}
int main() {
    quickSort(0, arr.size() - 1);
    //출력
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}