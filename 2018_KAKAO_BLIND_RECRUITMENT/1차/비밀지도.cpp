#include <iostream>
#include <vector>
using namespace std;

int two[16] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };

string intToMap(int a, int n) {
	int base = n - 1;
	string result = "";
	for (; base >= 0; base--) {
		if (two[base] <= a) {
			a -= two[base];
			result += "#";
		}
		else result += " ";
	}

	return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> result;
	for (int i = 0; i < n; i++) {
		string s1 = intToMap(arr1[i], n);
		string s2 = intToMap(arr2[i], n);

		string tmp = "";
		for (int j = 0; j < n; j++) {
			if (s1[j] == '#' || s2[j] == '#')
				tmp += "#";
			else tmp += " ";
		}

		result.push_back(tmp);
	}

	return result;
}

int main() {
	vector<string> v = solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}
