* BFS
    * queue의 자료형 
    ```c++
        struct node{int x, y, z, d;};
        std::queue<node> q;

        while(!q.empty()){
		    auto v = q.front();
	    	q.pop();
	    	// v를 이용한 연산
            // v.x, v.y, v.z, v.d로 사용 가능
	    }
* 재귀 함수
    * 쪼개지지 않는 가장 작은 작업들을 먼저 파악하는 것이 우선이다.
    * ex) n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘: 더 고를 원소가 없을때, 고른 원소들을 출력한다.

* bitmask
    * 첫번째 비트가지고 놀기
    ```c++
    // 첫번째 비트 위치 구하기
    int firstBit = (bits & -bits);
    // 첫번째 비트 끄기
    bits &= (bits - 1);
    // 모든 부분 집합 순회하기
    for (int subset = pizza; subset; subset = ((subset - 1) & pizza)) {
        
    }
    ```
* 문제 읽기
    * 문제 읽으면서 변수 이름, 갯수 생각해놓기