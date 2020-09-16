#include <iostream>
#include <vector>
using namespace std;

int snail[1000][1000];

int di[3] = { 1, 0, -1 };
int dj[3] = { 0, 1, -1 };

vector<int> solution(int n) {
	int index_i = -1, index_j = 0, dir = 0;
	int cnt = n, num = 1;
	while (cnt > 0) {
		for (int i = 0; i < cnt; i++) {
			index_i += di[dir];
			index_j += dj[dir];
			snail[index_i][index_j] = num++;
		}

		dir++; dir %= 3;
		cnt--;
	}

	vector<int> result;
	for (int i = 0; i < n; i++)
		for (int j = 0; snail[i][j]; j++)
			result.push_back(snail[i][j]);

	return result;
}
