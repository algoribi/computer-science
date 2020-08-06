#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // ex
    vector<int> arr = {9, 2, 7, 3, 1};
    // 선택 정렬
    for (int i = 0; i < arr.size(); i++) {
        int minn = arr[i];
        int index = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (minn > arr[j]) {
                minn = arr[j];
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
    // 출력
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}