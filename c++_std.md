vector
====
vector
----
* 자동으로 메모리가 할당되는 배열
    * 구문
    ```c++
    #include<vector>

    vector<int> v;
    v.assign(a, b)
    // a의 값으로 b개의 원소 할당
    v.front();
    // 첫번째 원소 참조
    v.back();
    // 마지막 원소 참조
    v.clear();
    // 초기화, capacity는 유지
    v.push_back(a);
    // 마지막 원소 뒤에 a 삼입
    v.pop_back(a);
    // 마지막 원소 제거
    v.reserve(n);
    // n개의 원소에 해당하는 메모리 동적할당.
    v.resize(n);
    // 크기를 n으로 변경
    v.size();
    // 원소의 개수
    ```

utility
====
pair
----
* 두 자료형을 묶을 수 있다.
* 첫번째 자료형에 접근하기 위해 first, 두번째 자료형에는 second로 접근 가능.
* nested pair 가능

limits
====
* 구문
    ```c++
    std::numeric_limits<T>::min()
    // T type이 가질 수 있는 최소한의 값.
    ```

string
====
substr
----

[reference](https://en.cppreference.com/w/cpp/string/basic_string/substr)

algorithm
====
next_permutation/prev_permutation
```c++
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

int main () {
  int myints[] = {1,2,3};

  std::sort (myints,myints+3);

  std::cout << "The 3! possible permutations with 3 elements:\n";
  do {
    std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
  } while ( std::next_permutation(myints,myints+3) );

  std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

  return 0;
}
```