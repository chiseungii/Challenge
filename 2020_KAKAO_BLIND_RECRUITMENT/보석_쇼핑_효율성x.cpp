#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define INF 1e6;

int dist[100000];

vector<int> solution(vector<string> gems) {
	map<string, int> check_gem;		// 중복 체크용

	for (int i = 0; i < gems.size(); i++)
		check_gem.insert(make_pair(gems[i], 0));

	// 거리 초기화
	for (int i = 0; i < gems.size(); i++) dist[i] = INF;

	// 최소 거리 구하기
	int cnt_gem = check_gem.size();		// 보석 개수
	for(int i=0; i<gems.size(); i++) {
		map<string, int> check(check_gem);	// 체크 복사

		// 자기 자신 카운트
		check.at(gems[i]) = 1;
		int cnt = 1;	// 보석 카운트

		if(cnt_gem==1) {
			dist[i] = 1;
			continue;
		}

		for(int j=i+1; j<gems.size(); j++) {
			if(check.at(gems[j])==0) {
				check.at(gems[j]) = 1;
				cnt++;
			}

			if(cnt == cnt_gem) {
				dist[i] = j - i + 1;
				break;
			}
		}
	}

	// 제일 짧은 거리 구하기
	int min_dist = INF;
	int min_index = -1;

	for(int i=0; i<gems.size(); i++) {
		if(dist[i]<min_dist) {
			min_dist = dist[i];
			min_index = i;
		}
	}

	vector<int> result;		// 결과 저장

	result.push_back(min_index + 1);
	result.push_back(min_index + dist[min_index]);

	return result;
}
