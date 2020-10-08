#include <iostream>
#include <string>
using namespace std;

int solution(int n) {
	// 앞뒤 반전 3진법
	string three = "";
	while (n > 0) {
		three += (n % 3 +'0');
		n /= 3;
	}

	// string 끝부터 다시 10진법으로
	int base = 1, answer = 0;
	for (int i = three.length() - 1; i >= 0; i--) {
		int tmp = (three[i] - '0') * base;
		answer += tmp;
		base *= 3;
	}

	return answer;
}
