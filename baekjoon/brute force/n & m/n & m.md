* n과 m 1~4
    * 중복허용 X
        * 다음의 코드를 사용한다.
        ```c++
        int answer[10];
        bool check[10] = {false};

        void go(int index, int n, int m) {
        	if (index == m + 1) {
        		for (int i = 1; i <= m; i++) {
        			cout << answer[i] << " ";
        		}
        		cout << '\n';
        		return;
        	}
        	for (int i = 1; i <= n; i++) {
        		if (check[i]) continue;
        		check[i] = true;
        		answer[index] = i;
        		go(index + 1, n, m);
        		check[i] = false;
        	}
        }
        /*중략*/
        go(1, n, m);
        ```
        * index 순서대로 사용 여부를 저장하는 배열 checks를 선언한 후 이미 사용된 수인지를 체크하면 된다.
    * 중복 허용
        * checks 배열을 제거한다.
    * 오름차순
        * 중복 허용에서, go 함수에 전에 사용된 수에 해당하는 prev 인자를 추가한다.
            * 재귀 함수가 들어있는 반복문의 시작점을 prev에서 한다.
        * 다만, 오름차순이 더이상 추가될 수 없는 수열이 존재하므로, 이를 검증하는 로직을 추가한다.
        ```c++
        if (m - index + 1 > n - prev) {
	    	return;
	    }
        ```
    * 비내림차순
        * 재귀 함수가 들어있는 반복문의 시작점을 prev에서 한다.
* n과 m 5~8
    * 모두 결국 n과 m 1~4로 귀결되는 문제들이다.
    * 중복 허용, 중복 허용 X, 오름차순, 비내림차순
    * 5~8은 수를 오름차순으로 저장해 놓으면 index 순서대로 증가하므로, 1,2,3, ... n 처럼 똑같이 생각할 수 있다. 
        * 1~4와 동일하다.
* n과 m 9~12
    * 주어진 수중 중복된 수가 존재한다.
        * 중복된 순열을 처리하는 로직을 추가해야 한다.
        * 다른 로직은 5~8문제들과 같다.
    * 9번(중복 허용 X)
        * 재귀함수를 포함하는 반복문 안에서 같은 수가 사용되면 중복되므로
        ```c++
        for (int i = 1; i <= n; i++) {
	    	if (numbers[i] == numbers[i - 1] && checks[i - 1] == false) continue; // checks를 검사한다.
	    	// 아래는 똑같다.
            if (checks[i]) continue;
	    	checks[i] = true;
	    	answer[index] = numbers[i];
	    	go(index + 1, n, m);
	    	checks[i] = false;
	    }
        ```
    * 10번
        * 비 내림차순이므로, 이번에는 같은 수를 사용한다면, 처음 사용되는 수만 제외하고 모두 중복처리한다.
        ```c++
        if (numbers[i] == numbers[i - 1] && i != prev + 1) continue;
        ```
    * 11, 12번
        * 중복이 허용되므로, 다른 조건이 필요하지 않다.
        ```c++
        if (numbers[i] == numbers[i - 1]) continue;
        ```