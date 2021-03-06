# 동적 메모리 할당(Dynamic Memory Allocation) 기술면접

- 동적 메모리 할당에 대해 설명해주세요.
- new/delete와 malloc/free의 차이
- new를 통해 동적 할당한 배열은 동적 배열인가요?

</br>

## 답안

- 동적 메모리 할당에 대해 설명해주세요.

  > 프로그램의 실행 시간 동안 사용자가 직접 사용할 메모리의 공간이나 시점을 결정하여 할당하는 것을 말한다. 이렇게 할당받은 메모리는 프로세스의 **힙(heap) 영역**에서 할당하며, 프로세스가 실행되는 동안 이 영역은 유지되므로 사용이 끝나면 메모리 낭비를 줄이기 위해 명시적으로 할당을 해제해주어야 한다.

- new/delete와 malloc/free의 차이

  > malloc/free는 라이브러리가 제공하는 함수이지만 new/delete는 언어(C++)가 제공하는 연산자이기 때문에 별도의 라이브러리 없이 사용할 수 있다.
  > malloc/free은 realloc을 통해 재할당이 가능하지만, new는 기존 메모리를 해제한 후에 다시 할당해줘야 한다.
  > malloc은 기본적으로 사이즈를 매개변수로 받고, 반환 타입이 void \*형이므로 sizeof()와 캐스트 연산자의 도움을 받아야 쉬운 코딩이 가능하다. 하지만 new는 할당할 타입을 지정해주면 알아서 할당할 타입의 포인터로 넘어오기 때문에 같은 타입의 포인터 변수로 받아오기만 하면 된다.
  > new의 경우 할당과 동시에 초기화가 가능하다.

- new를 통해 동적 할당한 배열은 동적 배열인가요?
  > **new**연산자를 통해 **동적 할당**한 배열은 **동적 배열**과는 다른 개념이다. new 연산자를 통해 만들어진 배열은 우리가 원하는 만큼의 크기를 동적으로 메모리를 할당받아 만들어진 크기가 고정된 **정적 배열**이다. 즉, **우리가 필요한 만큼 크기를 지정해서 메모리를 할당**해 주는 것이기 때문에 공간 할당에 있어서는 동적 할당이지만, 배열의 크기가 지정되어 있다는 점에서는 동적 배열이 아닌 셈이다. 동적 배열(dynamic array)은 크기가 고정되지 않은 배열을 의미한다.
