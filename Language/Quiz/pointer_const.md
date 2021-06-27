## 문제 : 다음 코드에서 에러가 발생하는 부분과 이유를 대시오.

```cpp
#include <iostream>
#define endl "\n"

using namespace std;

int main() {
    int num1 = 10;
    int num2 = 20;
    const int* ptr1 = &num1;

    ptr1 = &num2;
    *ptr1 = 30;

    cout << *ptr1 << endl;

    int* const ptr2 = &num1;

    ptr2 = &num2;
    *ptr2 = 30;

    cout << *ptr2 << endl;

    return 0;
}
```

</br>

## 답안

- ptr1의 경우
  const int\* ptr1 = &num1;
  '포인터가 가리키는 값'이 const이기 때문에 포인터 값은 변경이 가능하다.
  따라서 ptr1 = &num2; 는 가능하나
  \*ptr1 = 30; 는 불가능

- ptr2의 경우
  int\* const ptr2 = &num1;
  '포인터의 값'이 const이기 때문에 포인터가 가리키는 값은 변경이 가능하다.
  따라서 ptr2 = &num2; 는 에러를 발생시킨다.
  \*ptr2 = 30; 하지만 포인터가 가리키는 값인 \*ptr2의 값을 변경하는 것은 가능
