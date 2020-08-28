#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define HIT 1
#define MISS 5

int solution(int cacheSize, vector<string> cities) {
	if (cacheSize == 0) return MISS * cities.size();

	// 캐시 생성
	vector<pair<int, string>> Cache;	// 넣은 시간, 도시 이름
	for (int i = 0; i < cacheSize; i++)
		Cache.push_back(make_pair(0, ""));

	// 도시 넣기
	int num = 0;
	int sum_time = 0;
	for (int i = 0; i < cities.size(); i++) {
		// 소문자로 바꾸기
		string tmp = "";
		for (int j = 0; j < cities[i].length(); j++)
			tmp += tolower(cities[i][j]);

		// 있는지 확인
		bool exist = false;
		int min_index = 0, min_used = Cache[0].first;
		for (int j = 0; j < Cache.size(); j++) {
			if (Cache[j].first < min_used) {
				min_used = Cache[j].first;
				min_index = j;
			}
			if (Cache[j].second == tmp) {
				Cache[j].first = ++num;
				sum_time += HIT;
				exist = true;
				break;
			}
		}

		// 없으면 가장 적은 곳으로 넣기
		if (!exist) {
			Cache[min_index].first = ++num;
			Cache[min_index].second = tmp;
			sum_time += MISS;
		}
	}

	return sum_time;
}
