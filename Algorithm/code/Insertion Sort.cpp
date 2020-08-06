#include <iostream>
#include <vector>

using namespace std;

int main() {
    // ex
    vector<int> arr = {9, 2, 7, 3, 1};
    // 삽입 정렬
    for (int i = 1; i < arr.size(); i++) {
        int save = arr[i], j = 0;
        for (j = i - 1; j >= 0 && arr[j] > save; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = save;
    }
    // 출력
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}