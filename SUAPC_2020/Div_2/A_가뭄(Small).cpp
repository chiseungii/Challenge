#include <iostream>
using namespace std;

int main() {
	double d1, d2, d3; cin >> d1 >> d2 >> d3;
	double sum = (d1 + d2 + d3) / 2;

	bool impossible = false;
	double a = sum - d3;
	if (a <= 0) impossible = true;
	double b = sum - d2;
	if (b <= 0) impossible = true;
	double c = sum - d1;
	if (c <= 0) impossible = true;

	if (impossible) cout << -1 << endl;
	else {
		cout << 1 << endl;
		printf("%.1f %.1f %.1f\n", a, b, c);
	}
}
