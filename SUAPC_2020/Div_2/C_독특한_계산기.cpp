#include <iostream>
#include <deque>
#include <cstring>
#include <string>
using namespace std;

long long cal_result(long long a, long long b, char op) {
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	else if (op == '*') return a * b;
	else return a / b;
}

int main() {
	string cal; cin >> cal;

	deque<long long> nums;
	deque<char> ops;

	bool first_minus = false;
	if (cal[0] == '-') {
		first_minus = true;
		cal = cal.substr(1);
	}

	long long index = 0; long long a;
	for (long long i = 0; i < cal.length(); i++) {
		if (!isdigit(cal[i])) {
			a = stoll(cal.substr(index, i - index));
			// a = atoll(cal.substr(index, i - index).c_str());
			nums.push_back(a);
			ops.push_back(cal[i]);
			index = i + 1;
		}
	}
	a = stoll(cal.substr(index));
	// a = atoi(cal.substr(index).c_str());
	nums.push_back(a);
	if (first_minus) nums[0] = -nums[0];

	while (ops.size() > 1) {
		bool front_first = true;

		long long front_a = nums.front(); nums.pop_front();
		long long front_b = nums.front();
		long long back_b = nums.back(); nums.pop_back();
		long long back_a = nums.back();
		char front_op = ops.front();
		char back_op = ops.back();

		long long front_result = cal_result(front_a, front_b, front_op);
		long long back_result = cal_result(back_a, back_b, back_op);

		if ((back_op == '*' || back_op == '/') && (front_op == '+' || front_op == '-')) {
			front_first = false;
		}
		else if ((front_op == '*' || front_op == '/') && (back_op == '+' || back_op == '-'));
		else {
			if (back_result > front_result)
				front_first = false;
		}

		if (front_first) {
			nums.push_back(back_b);
			nums.pop_front();
			nums.push_front(front_result);
			ops.pop_front();
		}
		else {
			nums.push_front(front_a);
			nums.pop_back();
			nums.push_back(back_result);
			ops.pop_back();
		}
	}

	long long result;
	if (ops.size() == 1)
		result = cal_result(nums.front(), nums.back(), ops.front());
	else result = nums.front();

	cout << result << endl;
}
