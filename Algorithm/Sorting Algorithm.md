# 정렬 알고리즘(Sorting Algorithm)

## 선택 정렬(Selection Sort)

> 정렬하고자 하는 배열을 선형 탐색하여 최솟값을 찾아 가장 앞의 데이터와 교환해 나가는 방식이다. 이는 간단하게 구현할 수 있지만, 비효율적이라는 단점이 있다.

- Time Complexity

  - Best : O(n^2)
  - Avg : O(n^2)
  - Wast : **O(n^2)**

  **[C++ Code](https://github.com/algoribi/computer-science/blob/master/Algorithm/code/Selection%20Sort.cpp)**

</br>

## 버블 정렬(Bubble Sort)

> 배열에서 인접한 두 개의 데이터를 비교하여 가장 큰 값을 배열의 맨 끝으로 이동시키면서 정렬하는 방식이다. 따라서 정렬하고자 하는 원소의 개수(n)만큼을 두 번 반복한다.

- Time Complexity

  - Best : O(n^2)
  - Avg : O(n^2)
  - Wast : **O(n^2)**

  **[C++ Code](https://github.com/algoribi/computer-science/blob/master/Algorithm/code/Bubble%20Sort.cpp)**

</br>

## 삽입 정렬(Insertion Sort)

> 앞의 원소보다는 크고, 뒤의 원소보다는 작은 위치에 데이터를 삽입하는 방식이다.

- Time Complexity

  - Best : O(n)
  - Avg : O(n^2)
  - Wast : **O(n^2)**

  **[C++ Code](https://github.com/algoribi/computer-science/blob/master/Algorithm/code/Insertion%20Sort.cpp)**

</br>

## 퀵 정렬(Quick Sort)

> 퀵 정렬은 **분할 정복** 알고리즘을 이용하며, 특정한 값인 **피벗(Pivot)**을 기준으로 큰 숫자와 작은 숫자를 구분하여 정렬한다. 퀵 정렬은 Sorting 알고리즘 중에 가장 빠르다고 하여 Quick이라는 이름이 붙여졌지만, Worst Case에서는 그렇지 않다.

- Time Complexity

  - Best : O(N\*logN)
  - Avg : **O(N\*logN)**
  - Wast : **O(n^2)**

  **[C++ Code](https://github.com/algoribi/computer-science/blob/master/Algorithm/code/Quick%20Sort.cpp)**

</br>

## 병합 정렬(Merge Sort)

> 병합 정렬은 **분할 정복** 알고리즘을 이용하며, 더 이상 나누어지지 않을 때까지 반씩 분할하다가 더 이상 나누어지지 않는 때에는 자기 자신(원소 하나)을 반환한다. 항상 반으로 나누기 때문에 퀵 정렬(Quick Sorting)과 다르게 피벗(Pivot)이 필요 없고, 따라서 Wast case를 보장한다는 장점이 있다.

- Time Complexity

  - Best : O(N\*logN)
  - Avg : O(N\*logN)
  - Wast : **O(N\*logN)**

  **[C++ Code](https://github.com/algoribi/computer-science/blob/master/Algorithm/code/Merge%20Sort.cpp)**

</br>

## 힙 정렬(heap Sort)

> 힙 정렬은 **binary heap** 자료구조를 이용한 정렬 방법이다. 힙 정렬을 구현하는 것은 두 가지 방법이 존재한다. 하나는 정렬의 대상인 데이터들을 힙에 넣었다가 꺼내는 원리로 정렬을 하는 방법이고, 또 다른 방법은 기존의 배열을 heap으로 만들어주는 과정을 거쳐 꺼내주는 방법으로 정렬하는 것이다.

- Time Complexity

  - Best :O(N\*logN)
  - Avg : O(N\*logN)
  - Wast : **O(N\*logN)**

  **[C++ Code](https://github.com/algoribi/computer-science/blob/master/Algorithm/code/Heap%20Sort.cpp)**
