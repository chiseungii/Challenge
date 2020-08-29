#include <iostream>
#include <algorithm>
using namespace std;

int cnt_1[26][26];
int cnt_2[26][26];

int solution(string str1, string str2) {
	// str1 카운트
	bool empty_1 = true;
	for (int i = 0; i < str1.length() - 1; i++) {
		char a = tolower(str1[i]);
		char b = tolower(str1[i + 1]);

		if (!isalpha(a) || !isalpha(b)) continue;
		else {
			cnt_1[a - 'a'][b - 'a']++;
			empty_1 = false;
		}
	}

	// str2 카운트
	bool empty_2 = true;
	for (int i = 0; i < str2.length() - 1; i++) {
		char a = tolower(str2[i]);
		char b = tolower(str2[i + 1]);

		if (!isalpha(a) || !isalpha(b)) continue;
		else {
			cnt_2[a - 'a'][b - 'a']++;
			empty_2 = false;
		}
	}

	// 둘 다 공집합일 경우
	if (empty_1 && empty_2) return 65536;

	// 교집합과 합집합 카운트
	int cnt_inter = 0, cnt_union = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			cnt_union += max(cnt_1[i][j], cnt_2[i][j]);
			if (cnt_1[i][j] && cnt_2[i][j])
				cnt_inter += min(cnt_1[i][j], cnt_2[i][j]);
		}
	}

	// 계산
	cnt_inter *= 65536;
	return cnt_inter / cnt_union;
}
