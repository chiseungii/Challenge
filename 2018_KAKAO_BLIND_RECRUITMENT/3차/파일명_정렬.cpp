#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class File {
	int index;
	string HEAD, TAIL;
	int NUMBER;
	string origin;

public:
	File(int i, string h, int n, string t, string o) {
		index = i;
		HEAD = h;
		NUMBER = n;
		TAIL = t;
		origin = o;
	}
	int getIndex() { return index; }
	string getHEAD() { return HEAD; }
	int getNUMBER() { return NUMBER; }
	string getTAIL() { return TAIL; }
	string getOrigin() { return origin; }
};

bool compare(File f1, File f2) {
	if (f1.getHEAD() == f2.getHEAD()) {
		if (f1.getNUMBER() == f2.getNUMBER())
			return f1.getIndex() < f2.getIndex();
		else return f1.getNUMBER() < f2.getNUMBER();
	}
	else return f1.getHEAD() < f2.getHEAD();
}

vector<string> solution(vector<string> files) {
	// 세 부분 나눠서 넣기
	vector<File> F;
	for (int i = 0; i < files.size(); i++) {
		string tmp = files[i];

		// HEAD
		int index = 0;
		for (; !isdigit(tmp[index]); index++);
		string HEAD = tmp.substr(0, index);
		for (int j = 0; j < HEAD.length(); j++)
			if (isalpha(HEAD[j]))
				HEAD[j] = tolower(HEAD[j]);

		// NUMBER
		int before_index = index;
		for (; isdigit(tmp[index]); index++);
		string NUMBER = tmp.substr(before_index, index - before_index);
		int NUM = stoi(NUMBER);

		// TAIL
		string TAIL = tmp.substr(index);

		// push
		F.push_back(File(i, HEAD, NUM, TAIL, tmp));
	}
	
	// 정렬
	sort(F.begin(), F.end(), compare);

	// 정렬 순으로 다시 파일 이름 정리
	vector<string> result;
	for (int i = 0; i < F.size(); i++)
		result.push_back(F[i].getOrigin());

	return result;
}
