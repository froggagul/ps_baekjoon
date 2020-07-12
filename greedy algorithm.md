* 탐욕 알고리즘의 조건 (위키)
    * 탐욕 알고리즘이 잘 작동하는 문제는 대부분 탐욕스런 선택 조건(greedy choice property)과 최적 부분 구조 조건(optimal substructure)이라는 두 가지 조건이 만족된다. 탐욕스런 선택 조건은 앞의 선택이 이후의 선택에 영향을 주지 않는다는 것이며, 최적 부분 구조 조건은 문제에 대한 최적해가 부분문제에 대해서도 역시 최적해라는 것이다.
* LIS 알고리즘
    * 제일 긴 증가 수열을 구하는 알고리즘이다.
    * O(NlogN)에 가능
    * 배열 마지막 요소보다 새로운 수가 크다면, 배열에 넣는다.
    * 그렇지 않다면, 그 수가 들어갈 자리에 넣는다. (이분 탐색을 통해 들어갈 자리를 찾는다)
    ```c++
    /*12015.cpp*/
    #include <iostream>
    #include <queue>
    #include <algorithm>
    #include <vector>
    using namespace std;

    int main() {
    	int n;
    	cin >> n;
    	vector<int> v(n);
    	for (int i = 0; i < n; i++) {
    		cin >> v[i];
    	}
    	vector<int> res;
    	for (int i = 0; i < n; i++) {
    		int lo = lower_bound(res.begin(), res.end(), v[i]) - res.begin();   //res 배열에서 v[i]보다 작거나 같은 수 중 가장 큰 수가 있는 index를 찾는다.
    		if (lo == res.size()) { //v[i]가 res의 끝 수보다 크다면, push_back
    			res.push_back(v[i]);
    		}
    		else {
    			res[lo] = v[i]; // v[i]가 다른 수로 대체될 수 있다면, 대체한다.
    		}
    	}
    	cout << res.size() << '\n';
    	return 0;
    }
    ```