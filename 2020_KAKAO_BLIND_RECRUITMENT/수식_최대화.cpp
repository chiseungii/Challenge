#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long solution(string expression) {
	vector<string> split;	// 숫자, 연산자 다 잘라서 저장
	vector<string> ops;		// 연산자만 저장

	int before_index = 0;
	for(int i=0; i<expression.length(); i++) {
		if(!isdigit(expression[i])) {
			split.push_back(expression.substr(before_index, i - before_index));
			split.push_back(expression.substr(i, 1));

			before_index = i + 1;

			ops.push_back(expression.substr(i, 1));
		}
	}
	split.push_back(expression.substr(before_index));

	// 중복 제거
	sort(ops.begin(), ops.end());
	ops.erase(unique(ops.begin(), ops.end()), ops.end());

	vector<string> before = ops;	// 종료 조건 저장
	long long max = -1;

	while(1) {
		vector<string> cpy_split = split;
		
		for(int i=0; i<ops.size(); i++) {
			string op = ops[i];

			// 해당 연산자 찾아서 계산
			while(1) {
				int index = -1;

				for(int j=0; j<cpy_split.size(); j++) {
					if(cpy_split[j]==op) {
						index = j;
						break;
					}
				}

				if (index == -1) break;

				long long left = stoll(cpy_split[index - 1]);
				long long right = stoll(cpy_split[index + 1]);
				cpy_split.erase(cpy_split.begin() + index - 1, cpy_split.begin() + index + 2);

				long long result;
				switch(op[0]) {
				case '+':
					result = left + right;
					break;

				case '-':
					result = left - right;
					break;

				case '*':
					result = left * right;
					break;
				}

				if (index - 1 >= cpy_split.size()) cpy_split.push_back(to_string(result));
				else cpy_split.insert(cpy_split.begin() + index - 1, to_string(result));
			}
		}

		long long result = stoll(cpy_split[0]);
		if (result < 0) result = -result;
		if (result > max) max = result;
		
		// 다음 조합
		prev_permutation(ops.begin(), ops.end());
		if (ops == before) break;
	}

	return max;
}
