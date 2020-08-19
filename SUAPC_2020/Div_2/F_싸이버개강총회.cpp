#include <iostream>
// #include <vector>
#include <map>
using namespace std;

void toTime(string s, int& h, int& m) {
	h = (s[0] - '0') * 10 + (s[1] - '0');
	m = (s[3] - '0') * 10 + (s[4] - '0');
}

int main() {
	string S, E, Q; cin >> S >> E >> Q;
	int Sh, Sm; toTime(S, Sh, Sm);
	int Eh, Em; toTime(E, Eh, Em);
	int Qh, Qm; toTime(Q, Qh, Qm);

	int cnt = 0;
	// vector<string> check;
	map<string, int> check;
	while (1) {
		string time; cin >> time;
		if (time == "") break;
		string name; cin >> name;

		int h, m; toTime(time, h, m);
		// 입장 확인
		if ((h == Sh && m <= Sm) || (h < Sh)) {
			// check.push_back(name);
			if (check.count(name) == 0)
				check.insert(make_pair(name, 1));
		}
		else {
			// 퇴장 확인
			bool finish_chong = (h == Eh && m >= Em) || (h > Eh);
			bool finish_streaming = (h == Qh && m <= Qm) || (h < Qh);
			if (finish_chong && finish_streaming) {
				/*
				for (int i = 0; i < check.size(); i++) {
					if (check[i] == name) {
						cnt++;
						break;
					}
				}
				*/

				if (check.count(name)) {
					cnt++;
					check.erase(name);
				}
			}
		}
	}

	cout << cnt << endl;
}
