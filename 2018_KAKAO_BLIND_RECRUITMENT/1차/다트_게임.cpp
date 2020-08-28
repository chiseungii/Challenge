#include <iostream>
using namespace std;

int solution(string dartResult) {
	int score = 0;
	int before = 0;

	int index = 0;
	for (int i = 0; i < 3; i++) {
		// 점수 계산
		int tmp_score;
		if (dartResult[index + 1] == '0') {
			tmp_score = 10;
			index += 2;
		}
		else tmp_score = dartResult[index++] - '0';

		// bonus
		char bonus = dartResult[index++];
		if (bonus == 'D') tmp_score *= tmp_score;
		else if (bonus == 'T') tmp_score = tmp_score * tmp_score * tmp_score;

		// option
		if (index >= dartResult.length());
		else if (dartResult[index] == '*') {
			score += before;
			tmp_score *= 2;
			index++;
		}
		else if (dartResult[index] == '#') {
			tmp_score = -tmp_score;
			index++;
		}

		// 점수 합산
		score += tmp_score;
		before = tmp_score;
	}

	return score;
}
