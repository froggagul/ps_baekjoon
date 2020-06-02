* 그래프
    * 14226 : queue에 time을 배열 안에 넣고 처리하려했음, 그러면 각 상태를 저장하지 못하는 경우가 발생
        * queue : {{curr, clip} , time}의 형태로 해결
    * 1261 : deque 자료형 사용
        * 벽을 뚫는 경우와 뚫지 않는 경우로 나누어지기 때문에, 덱을 사용
        * 뚫는 경우에는 뒤에, 안 뚫는 경우에는 앞에 추가
        * 덱은 꼭 먼저 와야 하는 탐색이 있는 경우 사용하나..?
    * 1167 : 트리의 지름을 구하는 알고리즘을 배움 
        1. 아이디어
            * 정점에서 가장 먼 점, 그 점을 기준으로 다시 가장 먼점
            * 위에 대한 증명은 이걸 봤을때 기억나지 않는다면 증명 해볼것
        2. postorder
            * 또다른 풀이법으로는 정점을 선택한뒤, postorder을 통해 
            * 자손을 root로 하는 subtree의 지름 vs 각 자손을 통해 도달할 수 있는 두개의 가장 먼 거리들의 합 (현재 구현해보지 않음, 이후 오답할때 직접 구현해볼것)

* 부르트포스
    * 재귀
        * 1987 : n크기의 문자열을 받을때는 n+1크기만큼 미리 선언해줘야 함(\n 문자때문)