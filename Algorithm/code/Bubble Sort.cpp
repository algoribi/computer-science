#include <iostream>
#include <vector>

using namespace std;

int main() {
    // ex
    vector<int> arr = {9, 2, 7, 3, 1};
    // 버블 정렬
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size() - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // 출력
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}