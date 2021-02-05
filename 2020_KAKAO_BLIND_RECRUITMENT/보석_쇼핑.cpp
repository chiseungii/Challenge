/*
map, set 이용
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

#define INF 1e6;

vector<int> solution(vector<string> gems) {
	set<string> set_gems;			// 보석 개수 세기 위해서
	for (int i = 0; i < gems.size(); i++) set_gems.insert(gems[i]);
	int cnt_gem = set_gems.size();	// 보석 개수
	
	map<string, int> check_gem;		// 빈도수 측정
	check_gem[gems[0]]++;
	int len_gem = gems.size();
	
	int left = 0, right = 0;	// 왼쪽, 오른쪽 인덱스

	int min_dist = INF;
	int min_index = -1;
	
	while (right < len_gem && left <= right) {
		// 보석 개수 모자랄 경우
		if(check_gem.size() < cnt_gem) {
			right++;

			if (right == len_gem) break;
			check_gem[gems[right]]++;
		}
		// 보석 개수 맞는 경우
		else {
			// 길이가 더 짧을 경우
			if(right-left+1<min_dist) {
				min_dist = right - left + 1;
				min_index = left;
			}

			// left 더 짧게
			check_gem[gems[left++]]--;
			if (check_gem[gems[left - 1]] == 0)
				check_gem.erase(gems[left - 1]);
		}
	}

	vector<int> result;		// 결과 저장

	result.push_back(min_index + 1);
	result.push_back(min_dist + min_index);

	return result;
}
