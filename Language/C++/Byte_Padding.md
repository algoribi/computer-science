# 바이트 패딩(Byte Padding)

> 바이트 패딩이란 클래스나 구조체에 패딩 바이트를 추가하여 CPU 접근을 더 용이하게 해 주는 것을 말합니다.

- 자칫 공간 낭비처럼 보일 수 있는 불필요한 패딩 공간을 확보하면서까지 메모리의 크기를 맞추는 이유는 **캐시 hit율을 높여 cpu의 연산 횟수를 줄이기 위해서**이다.

```cpp
struct test {
    int a; // 4byte
    char c1; // 1byte
    char c2; // 1byte
    double d; // 8byte
    short s; // 2byte
};

int main() {
    std::cout << sizeof(test) << std::endl; // 24 출력
}
```

- 위의 예제 코드에서 구조체 test의 경우 자료형들의 총합은 16byte이므로 sizeof(test)를 하면 16을 출력할 것 같지만 24를 출력한다. 8byte는 어디서 온 것일까? 바로 바이트 패딩으로 인한 값이다.
- 내 경우 64bit CPU 때문에 한 번에 8byte씩 읽어온다. (34bit CPU는 한 번에 4byte) 즉, 처음 8byte만큼 읽어 올 때 int a, char c1, char c2를 읽고 남는 2byte만큼 padding 되었다. 그다음 double d를 8byte만큼 읽고, 마지막으로 남은 short s를 읽을 때 남는 6byte만큼 padding 된다. 따라서 24byte가 되는 것이다.

## 효율적인 공간 설계를 위해서는 이 구조체를 어떻게 설계하는 것이 좋을까?

- 처음 예제의 코드를 효율적으로 설계해보자.

```cpp
struct test {
   int a; // 4byte
   char c1; // 1byte
   char c2; // 1byte
   short s; // 2byte
   double d; // 8byte
};

int main() {
   std::cout << sizeof(test) << std::endl; // 16 출력
}
```

- 이렇게 설계한다면 padding 되는 공간이 없어 좀 더 효율적일 것이다. 따라서 구조체 혹은 클래스를 설계할 때 이런 부분을 염두하여 설계하도록 하자.
