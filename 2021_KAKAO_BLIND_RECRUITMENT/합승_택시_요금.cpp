/*
★ 다시 풀어보기 ★

INF 설정값에서 오류 남
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e6;

int graph[201][201];	// 그래프

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	// 그래프를 모두 무한대로 초기화
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			graph[i][j] = INF;

	// 자기 자신으로 가는 길은 0으로 초기화
	for (int i = 1; i <= n; i++)
		graph[i][i] = 0;

	// 길 정보 입력
	for(int i=0; i<fares.size(); i++) {
		vector<int> tmp = fares[i];

		graph[tmp[0]][tmp[1]] = tmp[2];
		graph[tmp[1]][tmp[0]] = tmp[2];
	}

	// n번 반복
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				graph[j][k] = min(graph[j][i] + graph[i][k], graph[j][k]);

	// 최단 거리 계산
	int min_cost = graph[s][1] + graph[1][a] + graph[1][b];

	for(int i=2; i<=n; i++) {
		int cost = graph[s][i] + graph[i][a] + graph[i][b];
		if (cost < min_cost) min_cost = cost;
	}

	return min_cost;
}
