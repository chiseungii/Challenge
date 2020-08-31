#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int searchCnt(string a, string b) {
	// a를 검색하는 것

	// a의 길이가 b보다 길 경우
	if (a.length() > b.length()) {
		int cnt = 0;
		bool diff = false;
		for (int i = 0; i < b.length(); i++) {
			cnt++;
			if (a[i] != b[i]) {
				diff = true;
				break;
			}
		}

		if (!diff) return cnt + 1;
		else return cnt;
	}
	// 길지 않은 경우
	else {
		int cnt = 0;
		for (int i = 0; i < a.length(); i++) {
			cnt++;
			if (a[i] != b[i]) break;
		}

		return cnt;
	}
}

int solution(vector<string> words) {
	// 단어들 먼저 정렬
	sort(words.begin(), words.end());

	int cnt_search = 0;

	// 제일 첫 단어
	string tmp = words[0];
	string cmp = words[1];
	cnt_search += searchCnt(tmp, cmp);

	// 제일 마지막 단어
	tmp = words[words.size() - 1];
	cmp = words[words.size() - 2];
	cnt_search += searchCnt(tmp, cmp);

	// 나머지 단어들
	for (int i = 1; i < words.size() - 1; i++) {
		tmp = words[i];

		// 왼쪽
		cmp = words[i - 1];
		int left_cnt = searchCnt(tmp, cmp);

		// 오른쪽
		cmp = words[i + 1];
		int right_cnt = searchCnt(tmp, cmp);

		// 둘 중 큰 수 더함
		cnt_search += max(left_cnt, right_cnt);
	}

	return cnt_search;
}
