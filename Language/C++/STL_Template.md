# 표준 템플릿 라이브러리(STL : Standard Template Library)

> 프로그램에 필요한 알고리즘, 컨테이너, 함수자, 반복자를 **Template**으로 제공하는 라이브러리이다. C++ template을 통해 제네릭(generic)한 프로그래밍이 가능하다.

<img src="/img/template.PNG">

- STL의 대표적인 컨테이너인 vector도 template를 통해 만들어진 것을 볼 수 있다.

</br>

## 템플릿(Template)이란?

> 함수나 클래스를 개별적으로 다시 작성하지 않고도, 여러 자료형에서 동작할 수 있게 한다.

### 함수 템플릿(Function Template)

> 함수의 기능은 명확하지만, 자료형을 모호하게 두는 것.

- 예를 들어 인자 2개를 입력받아 더한 값을 return 하는 함수를 만들어보자.

```cpp
int sum(int a, int b) {
    return a + b;
}

double sum(double a, double b) {
    return a + b;
}
```

- **오버로딩(overloading)**을 통해 필요한 자료형의 수 만큼 똑같은 구조의 함수를 여러 개 정의해 줘야 했다. 하지만 template을 사용하면 일일이 오버로딩을 할 필요 없이 여러 자료형에 대해 동작할 수 있게 해준다.

```CPP
#include <iostream>

template<typenamte T>
T sum(T a, T b) {
    return a + b;
}

int main() {
    std::cout << sum(1, 2) << std::endl; // int 형
    std::cout << sum(1.2, 2.5) std::endl; // double 형

    return 0;
}

```

- 이때 템플릿을 통해 작성된 함수는 호출되기 전까지 코드로만 존재하다가 호출이 되는 순간 그 타입에 맞춰서 컴파일된다.
