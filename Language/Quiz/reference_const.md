## 문제 : 아래의 코드는 오류가 난다. 이 코드를 작동할 수 있도록 수정해 보시오.

> (단, 기존의 코드를 주석처리 하거나 지우는 것은 금지)

```cpp
#include <iostream>
#define endl "\n"

using namespace std;

int main() {
    int& ref = 5;

    cout << ref << endl;

    return 0;
}
```

</br>

## 답안

```cpp
    // int& ref = 5;의 앞에 const를 추가한다.
    const int& ref = 5;
```

레퍼런스는 상수를 참조할 수 없지만 const를 선언하게 되면 상숫값도 참조할 수 있다.
프로그램상에서 변수명이 없는 임시 변수에 이 상숫값을 저장하고,
그 임시 변수를 레퍼런스가 참조하게 되면서 별명을 얻게 된다.
이때 이 임시 변수의 값을 변경하는 것이 문제를 유발하기 쉽기 때문에 const 속성을 가진
레퍼런스만 상숫값을 참조할 수 있다.
이때 const로 선언되었기 때문에 값의 변경은 불가능하다.
