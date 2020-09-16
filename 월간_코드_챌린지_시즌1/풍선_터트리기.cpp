#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int leftMin[1000000];
int rightMin[1000000];

int solution(vector<int> a) {
	int cnt = 0;

	// 가장 작은 수
	int minimum = *min_element(a.begin(), a.end());

	// 양쪽 끝 수
	cnt += 2;

	// 왼쪽 최소값
	leftMin[0] = a.front();
	for (int i = 1; i < a.size(); i++) {
		if (a[i] < leftMin[i - 1])
			leftMin[i] = a[i];
		else leftMin[i] = leftMin[i - 1];
	}

	// 오른쪽 최소값
	rightMin[a.size() - 1] = a.back();
	for (int i = a.size() - 2; i >= 0; i--) {
		if (a[i] < rightMin[i + 1])
			rightMin[i] = a[i];
		else rightMin[i] = rightMin[i + 1];
	}

	// 나머지 수
	for (int i = 1; i < a.size() - 1; i++) {
		if (leftMin[i] >= a[i] || rightMin[i] >= a[i])
			cnt++;
	}

	return cnt;
}
