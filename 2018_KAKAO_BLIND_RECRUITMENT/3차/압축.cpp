#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> solution(string msg) {
	// 사전 초기화
	vector<string> dictionary;
	for (int i = 0; i < 26; i++) {
		char c = i + 'A';
		string tmp = "";
		tmp += c;
		dictionary.push_back(tmp);
	}

	// msg 순회
	int max_len = 1;
	vector<int> nums;
	for (int i = 0; i < msg.length();) {
		for (int j = max_len; j >= 1; j--) {
			string tmp;
			if (i + j - 1 < msg.length())
				tmp = msg.substr(i, j);
			else tmp = msg.substr(i);

			bool exist = false;
			for (int k = 0; k < dictionary.size(); k++) {
				if (dictionary[k] == tmp) {
					exist = true;
					nums.push_back(k + 1);
					break;
				}
			}

			if (exist) {
				int copy_i = i;
				i += tmp.length();
				if (copy_i + j < msg.length()) {
					dictionary.push_back(msg.substr(copy_i, j + 1));
					if (j + 1 > max_len) max_len = j + 1;
					break;
				}
			}
		}
	}

	return nums;
}
