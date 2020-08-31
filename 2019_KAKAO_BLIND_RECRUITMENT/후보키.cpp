#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

char check[256];

string plusOne(int n, string &s) {
	int index = s.length() - 1;

	if (s[index] == '0') {
		s[index] = '1';
		return s;
	}
	else {
		int carry = 1;
		while (index >= 0) {
			int sum = s[index] - '0' + carry;
			carry = sum / 2;
			s[index--] = (sum % 2) + '0';
		}

		return s;
	}
}

bool isKey(vector<vector<string>> relation, string num, int col, int row) {
	for (int i = 0; i < row - 1; i++) {
		string tmp_1 = "";
		for (int j = 0; j < col; j++)
			if (num[j] == '1')
				tmp_1 += relation[i][j];

		for (int j = i + 1; j < row; j++) {
			string tmp_2 = "";
			for (int k = 0; k < col; k++)
				if (num[k] == '1')
					tmp_2 += relation[j][k];

			if (tmp_1 == tmp_2) return false;
		}
	}

	return true;
}

int solution(vector<vector<string>> relation) {
	int col_len = relation[0].size();
	int row_len = relation.size();
	int num = 0; string num_two = "";
	for (int i = 0; i < col_len; i++) num_two += "0";
	int num_end = pow(2, col_len) - 1;

	int cnt_key = 0;
	while (1) {
		num++; plusOne(col_len, num_two);

		if (!check[num] && isKey(relation, num_two, col_len, row_len)) {
			// check[num] = 1;
			cnt_key++;
			for (int i = num + 1; i <= num_end; i++)
				if ((num & i) == num) check[i] = 1;
		}

		if (num == num_end) break;
	}

	return cnt_key;
}
