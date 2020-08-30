// 시작 시간에 -999 하는 이유 아직 모름

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// char check[1000];

class TimeTable {
	bool start;
	int num;
	int ms;

public:
	TimeTable(bool s, int n, int ms) {
		start = s;
		num = n;
		this->ms = ms;
	}
	bool getStart() { return start; }
	int getNum() { return num; }
	int getMs() { return ms; }
};

bool compare(TimeTable t1, TimeTable t2) {
	if (t1.getMs() == t2.getMs()) {
		if (t1.getStart()) return true;
		else return false;
	}
	return t1.getMs() < t2.getMs();
}

int strToMs(string s) {
	int hour = stoi(s.substr(0, 2));
	int min = stoi(s.substr(3, 2));
	int sec = stoi(s.substr(6, 2));
	int ms = stoi(s.substr(9));

	sec += min * 60 + hour * 3600;
	ms += sec * 1000;
	
	return ms;
}

int strToDis(string s) {
	int len = s.length() - 1;
	double tmp = stod(s.substr(0, len));
	tmp *= 1000;

	return (int)tmp;
}

int solution(vector<string> lines) {
	// 시작시간과 끝시간 구별해서 ms 단위로 변환
	vector<TimeTable> MS;
	for (int i = 0; i < lines.size(); i++) {
		string tmp = lines[i];
		int index = 11;
		for (; tmp[index] != ' '; index++);

		int ms_end = strToMs(tmp.substr(11, index - 11));
		MS.push_back(TimeTable(false, i, ms_end));

		int dis_ms = strToDis(tmp.substr(index + 1));
		int ms_start = ms_end - dis_ms + 1 - 999;
		MS.push_back(TimeTable(true, i, ms_start));
	}
	// 정렬
	sort(MS.begin(), MS.end(), compare);

	/*
	// init
	for (int i = 0; i < lines.size(); i++)
		check[i] = 0;
	*/

	// count
	int max_cnt = 0, cnt = 0;
	for (int i = 0; i < MS.size(); i++) {
		TimeTable TT = MS[i];

		if (TT.getStart()) cnt++;
		else cnt--;

		if (cnt > max_cnt) max_cnt = cnt;
	}

	return max_cnt;
}
