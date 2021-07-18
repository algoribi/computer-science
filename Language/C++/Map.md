# Map & UnorderedMap

## std::map

> Map이란 Key와 Value를 가진 집합으로, 중복을 허용하지 않는 컨테이너를 말한다.

- 레드블랙 트리(Red-Black Tree)를 기반으로 구현되어 있다. 따라서 모든 데이터는 정렬되어 저장되며, 정렬이 필요하지 않은 경우에도 자동으로 정렬되기 때문에 불필요하게 감수해야 하는 오버헤드가 발생했다.
- 입력되는 key 값의 분포가 고르지 못할 경우 balancing에 대한 비용이 계속 들어가기 때문에 성능이 저하된다. 동시에 self-balancing이 있기 때문에 최악의 경우에도 탐색속도는 **O(logN)**으로 보장된다.

## std::unordered_map

> c++ 11 이전엔 정렬이 필요하지 않은 경우에도 std::map을 사용하여 불필요한 오버헤드를 감수해야 했다. 그때 사용하던 것이 비표준 컨테이너인 stdext::hash_map이다. 이후 STL 표준 컨테이너에 hash_map과 거의 동일한 기능을 제공하는 unordered_map이 추가되었다.(TR1부터 추가되었지만, C++ 11 에서 최적화 작업이 이루어졌다고 한다.) [MSDN의 hash_map 페이지](https://docs.microsoft.com/ko-kr/cpp/standard-library/hash-map-class?view=msvc-160)에도 표준인 unordered_map 사용을 권장한다.

- 해시 테이블(hash_table)을 기반으로 구현되어 있다. 따라서 데이터를 자동으로 정렬하지 않는다.
- 충분한 hash_table의 크기만 주어진다면 데이터양이 많더라도 검색, 삽입, 삭제 연산의 성능을 보장할 수 있다.

### 결론

- 데이터가 많은 경우 unordered_map이 map보다 성능 면에서 유리하다.
- 문자열을 key로 사용하는 경우 문자열의 길이가 길어질수록 unordered_map의 성능이 map보다 떨어진다. (문자열 비교 함수의 성능이 문자열 전체를 hashing 하는 것에 비해 우수하기 때문)
- key 값의 분포가 고르지 못한 경우 map의 성능이 저하될 수 있다. (self-balancing)
