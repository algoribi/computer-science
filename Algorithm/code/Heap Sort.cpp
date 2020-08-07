#include <iostream>
#define size 8

using namespace std;

int heap[size] = {7, 6, 2, 8, 3, 5, 4, 1};

int main() {
    for (int i = 1; i < size; i++) {
        int c = i;
        do {
            int root = (c - 1) / 2;
            if (heap[root] < heap[c]) {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
    for (int i = size - 1; i >= 0; i--) {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int c = 1;
        do {
            c = 2 * root + 1;
            if (c < i - 1 && heap[c] < heap[c + 1])
                c++;
            if (c < i && heap[root] < heap[c]) {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < i);
    }

    //출력
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    return 0;
}