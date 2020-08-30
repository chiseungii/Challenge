#include <iostream>
using namespace std;

string changeTen(int base, int n) {
	string result = "";
	while (n > 0) {
		int mod = n % base;
		n /= base;

		char c;
		if (mod == 10) c = 'A';
		else if (mod == 11) c = 'B';
		else if (mod == 12) c = 'C';
		else if (mod == 13) c = 'D';
		else if (mod == 14) c = 'E';
		else if (mod == 15) c = 'F';
		else c = mod + '0';

		result = c + result;
	}

	return result;
}

string solution(int n, int t, int m, int p) {
	string result = "";
	string nums = "0";
	int num = 0, index = p - 1;
	while (1) {
		// 숫자 모자라면 채우기
		while (index >= nums.length())
			nums += changeTen(n, ++num);

		// string 너무 커지면 자르기
		if (nums.length() > 100) {
			nums = nums.substr(index);
			index = 0;
		}

		// 자기 차례 숫자 채우기
		result += nums[index];
		index += m;
		t--;

		// 개수 다 맞췄으면 종료
		if (t == 0) break;
	}

	return result;
}
