// 떡국

#include <iostream>
#include <map>
using namespace std;

int main() {
	int N; cin >> N;	// 떡국 그릇 개수
	map<int, int> plates;	// <크기, 개수>
	int max_cnt = 0;	// 접시 개수 최대값

	for (int i = 0; i < N; i++) {
		int c; cin >> c;
		plates[c]++;

		if (plates[c] > max_cnt) {
			max_cnt = plates[c];
		}
	}

	cout << max_cnt << endl;
}
