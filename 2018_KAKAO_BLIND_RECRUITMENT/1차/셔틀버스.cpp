#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int strToMin(string s) {
	int hour = (s[0] - '0') * 10 + (s[1] - '0');
	int min = (s[3] - '0') * 10 + (s[4] - '0');
	min += hour * 60;

	return min;
}

string minToStr(int n) {
	int hour = n / 60;
	int min = n % 60;

	string result = "";
	if (hour < 10) result += "0";
	result += to_string(hour);
	result += ":";
	if (min < 10) result += "0";
	result += to_string(min);

	return result;
}

string solution(int n, int t, int m, vector<string> timetable) {
	// 분 단위로 변환 후 정렬
	vector<int> timetable_min;
	for (int i = 0; i < timetable.size(); i++) {
		if (timetable[i] == "24:00") continue;
		timetable_min.push_back(strToMin(timetable[i]));
	}
	sort(timetable_min.begin(), timetable_min.end());

	// 버스 시간표 저장
	vector<int> bus_timetable;
	bus_timetable.push_back(540);
	for (int i = 0; i < n - 1; i++)
		bus_timetable.push_back(bus_timetable.back() + t);

	// 마지막 바로 전 셔틀까지 태움
	int crew_index = 0;
	for (int i = 0; i < bus_timetable.size() - 1; i++) {
		int tmp_time = bus_timetable[i];
		int crew_in_bus = 0;
		while (1) {
			// 더 이상 기다리는 크루가 없을 때
			if (crew_index >= timetable_min.size()) break;
			// 셔틀버스가 도착했을 때
			if (timetable_min[crew_index] > tmp_time) break;
			// 셔틀에 태움
			crew_in_bus++;
			crew_index++;

			// 셔틀 다 차면 떠남
			if (crew_in_bus >= m) break;
		}
	}

	// 마지막 셔틀
	int last_time = bus_timetable[bus_timetable.size() - 1];
	int crew_in_last_bus = 0;
	for (; crew_index < timetable_min.size() && timetable_min[crew_index] <= last_time; crew_index++)
		crew_in_last_bus++;

	// 자리가 있을 경우
	if (crew_in_last_bus < m) return minToStr(last_time);
	// 자리가 없을 경우
	else {
		int con_index = crew_index - (crew_in_last_bus - m + 1);
		int con_time = timetable_min[con_index] - 1;
		return minToStr(con_time);
	}
}
