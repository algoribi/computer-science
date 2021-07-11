# 동적 메모리 할당(Dynamic Memory Allocation)

> 프로그램의 실행 시간 동안 사용자가 직접 사용할 메모리의 공간이나 시점을 결정하여 할당하는 것을 말한다. 이렇게 할당받은 메모리는 프로세스의 **힙(heap) 영역**에서 할당하며, 프로세스가 실행되는 동안 이 영역은 유지되므로 사용이 끝나면 메모리 낭비를 줄이기 위해 명시적으로 할당을 해제해주어야 한다.

- 동적 할당의 방법으로는 C++에서 **new**와 **malloc**이 있다. (C의 경우 malloc만 가능)

## new / delete 연산자를 통한 동적 할당

```cpp
    // int(4byte)의 크기만큼 heap 영역에 동적으로 메모리 할당
    int* num = new int;
    *num = 5;
    // 할당한 메모리 해제
    delete num;

    // 배열의 동적 할당 예시
    int a = 10;
    int* arr = new int[a];
    // 배열의 경우 메모리 해제 시 배열이라는 것을 명시해주기 위해 대괄호를 붙인다.
    delete[] arr;
```

- 이때 주의해야 할 것은 **new**연산자를 통해 **동적 할당**한 배열은 **동적 배열**과는 다른 개념이다. 위의 예제에서 배열 arr의 경우 new 연산자를 통해 우리가 원하는 만큼의 크기(a)를 동적으로 메모리를 할당받아 만들어진 크기가 고정된 **정적 배열**이다. 즉, **우리가 필요한 만큼 크기를 지정해서 메모리를 할당**해 주는 것이기 때문에 공간 할당에 있어서는 동적 할당이지만, 배열의 크기가 지정되어 있다는 점에서는 동적 배열이 아닌 셈이다. 동적 배열(dynamic array)은 크기가 고정되지 않은 배열을 의미한다.

```cpp
    // new의 여러 초기화 방법
    int* num1 = new int;
    *num1 = 5;
    delete num1;

    int* num2 = new int(5);
    delete num2;

    int* num3 = new int[5]{ 0, 1, 2, 3, 4 };
    delete[] num3;

    int* num4 = new int[5]{}; // 0으로 초기화
    delete[] num4;

    char* arr{ new char[20]{ "Hello, world!!" } };
    delete[] arr;
```

</br>

## malloc / free 연산자를 통한 동적 할당

```cpp
    // 1byte만큼 메모리 할당
    char *c1 = (char*)malloc(1);
    *c1 = 'a';
    free(c1); // 메모리 해제

    // sizeof를 통해 char의 크기(1byte)만큼 메모리 할당
    char *c2 = (char*)malloc(sizeof(char));
    *c2 = 'a';
    free(c2); // 메모리 해제

    // 배열의 동적 할당 예시
    // int의 크기(4byte) * 4개만큼 메모리 할당(1차원 배열)
    int *arr = (int*)malloc(sizeof(int) * 4);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    free(arr); // 메모리 해제
```

</br>

## new / delete 와 malloc / free의 차이점

- malloc/free는 라이브러리가 제공하는 함수이지만 new/delete는 언어(C++)가 제공하는 연산자이기 때문에 별도의 라이브러리 없이 사용할 수 있다.
- malloc/free은 realloc을 통해 재할당이 가능하지만, new는 기존 메모리를 해제한 후에 다시 할당해줘야 한다.
- malloc은 기본적으로 사이즈를 매개변수로 받고, 반환 타입이 void \*형이므로 sizeof()와 캐스트 연산자의 도움을 받아야 쉬운 코딩이 가능하다. 하지만 new는 할당할 타입을 지정해주면 알아서 할당할 타입의 포인터로 넘어오기 때문에 같은 타입의 포인터 변수로 받아오기만 하면 된다.
- new의 경우 할당과 동시에 초기화가 가능하다.

</br>

### 번외 : 정적 메모리 할당(Static Memory Allocation)

> 정적 메모리 할당은 메모리의 크기가 하드 코딩되어 있기 때문에 프로그램이 실행될 때 이미 해당 메모리의 크기가 결정된다.

```cpp
    // 우리가 사용한 이러한 메모리 할당 방식이 바로 정적 메모리 할당이다.
    int a;
    int arr[100];
    char s[] = "Hello, world!";
```

- 장점 : 메모리 해제를 필요로 하지 않기 때문에 이로 인한 메모리 누수와 같은 문제를 신경 쓰지 않아도 된다. 정적 할당된 메모리는 프로그램의 실행 도중에 해제되지 않고, 프로그램이 종료될 때 운영 체제가 알아서 회수한다.
- 단점 : 메모리의 크기가 하드 코딩되어 있고, 이를 컴파일 단계에서 할당받기 때문에 한 번 컴파일을 시작하면 그 이후로는 추가로 변수나 배열을 선언하거나 크기를 바꿀 수 없다. 따라서 이로 인해 메모리 공간의 낭비가 발생할 수 있다.