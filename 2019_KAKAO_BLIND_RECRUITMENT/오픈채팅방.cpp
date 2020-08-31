#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define ENTER 1
#define LEAVE 2
// #define CHANGE 3

vector<string> solution(vector<string> record) {
	vector<string> script;	// return할 것
	vector<pair<string, int>> log;	// id, action
	map<string, string> user_list;
	for (int i = 0; i < record.size(); i++) {
		string tmp = record[i];

		// action 분리
		int index = 0;
		for (; tmp[index] != ' '; index++);
		string action = tmp.substr(0, index);

		// LEAVE 일 경우
		if (action == "Leave") {
			string id = tmp.substr(index + 1);
			log.push_back(make_pair(id, LEAVE));
		}
		else {
			// id 분리
			int before_index = ++index;
			for (; tmp[index] != ' '; index++);
			string id = tmp.substr(before_index, index - before_index);

			// nickname 분리
			string nickname = tmp.substr(index + 1);

			// ENTER 일 경우
			if (action == "Enter")
				log.push_back(make_pair(id, ENTER));
			
			// 닉네임 업데이트
			user_list[id] = nickname;
		}
	}

	// log에 따라 script 저장
	for (int i = 0; i < log.size(); i++) {
		string id = log[i].first;
		int action = log[i].second;
		string nickname = user_list[id];

		if (action == ENTER)
			script.push_back(nickname + "님이 들어왔습니다.");
		else script.push_back(nickname + "님이 나갔습니다.");
	}

	return script;
}
