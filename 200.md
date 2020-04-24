자료구조
====
스택
----
* 스택은 한쪽 끝에서만 자료를 넣고 뺄 수 있는 자료구조이다. LIFO (Last In First Out)
* 제일 위에 있는 것(top)만 알 수 있는 자료구조(원칙적으로)
* 제일 위에 있는 것이 의미있을때 쓰는 것이 좋다.
* 라이브러리에 사용해보자.(문제를 많이 해결하고 싶을때는)
* 구현: 일차원 배열 하나로 구현 가능
```c
int stack[10000];
int size;
```
* 관련 함수 구현
```c
void push(int data) {
    stack[size] = data;
    size += 1;
}
void pop() {
    stack[size - 1] = 0;
    size -= 1;
}
```
* Q. 단어 뒤집기
  * N개의 수를 스택에 넣었다가 빼면 순서가 역순이 된다.
  * 알파벳을 스택에 넣고, 공백이나 문자열의 끝이면 스택에서 모두 빼내서 역순을 만든다.

큐
----
* 한쪽 끝에서만 자료를 넣고 다른 한쪽 끝에서만 뺄 수 있는 자료구조
* 먼저 넣은 것이 가장 먼저 나옴
* push, pop, empty, size: stack과 동일
* front/back: 가장 앞/뒤에있는 자료를 보는 연산
* c++의 경우에는 STL의 queue
* JAVA는 java.util.Queue

덱
----
* 양 끝에서만 자료를 넣고 양 끝에서 뺄 수 있는 자료구조
* double-ended queue의 약자(Deque)