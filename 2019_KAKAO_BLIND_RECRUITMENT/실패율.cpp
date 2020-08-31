#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt_clear[501];	// 클리어한 사람 수
int cnt_state[501];	// 현재 스테이지에 있는 사람 수

bool compare(pair<int, double> p1, pair<int, double> p2) {
	if (p1.second == p2.second)
		return p1.first < p2.first;
	else return p1.second > p2.second;
}

vector<int> solution(int N, vector<int> stages) {
	// count
	for (int i = 0; i < stages.size(); i++) {
		int tmp = stages[i];

		if (tmp == N + 1)
			for (int j = 1; j <= N; j++)
				cnt_clear[j]++;
		else {
			for (int j = 1; j < tmp; j++)
				cnt_clear[j]++;
			cnt_state[tmp]++;
		}
	}

	vector<pair<int, double>> rate;	// 스테이지 넘버, 실패율
	for (int j = 1; j <= N; j++) {
		double miss_rate;
		if (!cnt_state[j] && !cnt_clear[j]) miss_rate = 0;
		else miss_rate = (double)cnt_state[j] / (double)(cnt_state[j] + cnt_clear[j]);
		rate.push_back(make_pair(j, miss_rate));
	}
	sort(rate.begin(), rate.end(), compare);

	vector<int> result;
	for (int i = 0; i < rate.size(); i++)
		result.push_back(rate[i].first);

	return result;
}
