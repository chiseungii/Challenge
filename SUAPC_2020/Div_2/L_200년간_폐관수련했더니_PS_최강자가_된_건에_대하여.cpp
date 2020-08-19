#include <iostream>
#include <vector>
using namespace std;

#define POSSIBLE 0
#define EXCEPT_THIS 1
#define EXCEPT_BEFORE 2
#define IMPOSSIBLE 3

int main() {
	int N; cin >> N;

	vector<pair<int, int>> cups;	// 상금 상한, 상금
	for (int i = 0; i < N; i++) {
		int x, p; cin >> x >> p;
		cups.push_back(make_pair(x, p));
	}

	long long sum_price = 0;
	int result = POSSIBLE, except_index;
	for (int i = 0; i < N; i++) {
		if (sum_price > cups[i].first) {
			result = EXCEPT_THIS;
			except_index = i;
			break;
		}
		else sum_price += cups[i].second;
	}

	if (result == EXCEPT_THIS) {
		sum_price = 0; result = POSSIBLE;
		for (int i = 0; i < N; i++) {
			if (i == except_index) continue;
			else if (sum_price > cups[i].first) {
				result = EXCEPT_BEFORE;
				break;
			}
			else sum_price += cups[i].second;
		}
	}

	if (result == EXCEPT_BEFORE) {
		int max_p = -1, max_index = -1;
		for (int i = 0; i < except_index; i++) {
			if (cups[i].second > max_p) {
				max_p = cups[i].second;
				max_index = i;
			}
		}

		sum_price = 0; result = POSSIBLE;
		for (int i = 0; i < N; i++) {
			if (i == max_index) continue;
			else if (sum_price > cups[i].first) {
				result = IMPOSSIBLE;
				break;
			}
			else sum_price += cups[i].second;
		}
	}

	if (result == POSSIBLE) cout << "Kkeo-eok\n";
	else cout << "Zzz\n";
}
