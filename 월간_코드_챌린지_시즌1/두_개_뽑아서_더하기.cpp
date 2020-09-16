#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isIn(vector<int> v, int n) {
	for (int i = 0; i < v.size(); i++)
		if (v[i] == n) return true;

	return false;
}

vector<int> solution(vector<int> numbers) {
	vector<int> result;
	for (int i = 0; i < numbers.size() - 1; i++)
		for (int j = i + 1; j < numbers.size(); j++)
			if (!isIn(result, numbers[i] + numbers[j]))
				result.push_back(numbers[i] + numbers[j]);

	sort(result.begin(), result.end());
	return result;
}
