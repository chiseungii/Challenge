// str.find() 다시 공부 필요

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Song {
	string title;
	int playTime;
	int num;

public:
	Song(string t, int p, int n) {
		title = t;
		playTime = p;
		num = n;
	}
	string getTitle() { return title; }
	int getPlayTime() { return playTime; }
	int getNum() { return num; }
};

int strToMin(string s) {
	int hour = (s[0] - '0') * 10 + (s[1] - '0');
	int min = (s[3] - '0') * 10 + (s[4] - '0');
	min += hour * 60;

	return min;
}

bool compare(Song s1, Song s2) {
	if (s1.getPlayTime() == s2.getPlayTime())
		return s1.getNum() < s2.getNum();
	else return s1.getPlayTime() > s2.getPlayTime();
}

string replaceAll(string& m, string pattern, string replace) {
	int pos = 0;
	while ((pos = m.find(pattern, pos)) != string::npos) {
		m.replace(m.begin() + pos, m.begin() + pos + pattern.length(), replace);
		pos += replace.length();
	}

	return m;
}

string solution(string m, vector<string> musicinfos) {
	vector<Song> possible;	// 노래제목, 입력시간
	for (int i = 0; i < musicinfos.size(); i++) {
		string tmp = musicinfos[i];

		// 재생 시작 시각
		int index = 0;
		for (; tmp[index] != ','; index++);
		int playStart = strToMin(tmp.substr(0, index));

		// 재생 끝난 시각
		int before_index = ++index;
		for (; tmp[index] != ','; index++);
		int playEnd = strToMin(tmp.substr(before_index, index - before_index));

		// 노래 제목
		before_index = ++index;
		for (; tmp[index] != ','; index++);
		string title = tmp.substr(before_index, index - before_index);

		// 음계
		string code = tmp.substr(index + 1);
		replaceAll(code, "C#", "c");
		replaceAll(code, "D#", "d");
		replaceAll(code, "F#", "f");
		replaceAll(code, "G#", "g");
		replaceAll(code, "A#", "a");

		// 재생시간에 맞게 음계 만들기
		int playTime = playEnd - playStart;
		string song = "";
		index = 0;
		for (int i = 0; i < playTime; i++) {
			song += code[index++];
			if (index == code.size()) index = 0;
		}

		// 들은 음악이 포함되는지 확인
		replaceAll(m, "C#", "c");
		replaceAll(m, "D#", "d");
		replaceAll(m, "F#", "f");
		replaceAll(m, "G#", "g");
		replaceAll(m, "A#", "a");

		if (song.find(m) != string::npos) {
			possible.push_back(Song(title, playTime, i));
		}
	}

	if (possible.empty()) return "(None)";
	else {
		sort(possible.begin(), possible.end(), compare);
		return possible[0].getTitle();
	}
}
