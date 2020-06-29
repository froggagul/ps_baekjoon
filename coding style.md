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