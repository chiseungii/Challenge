#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
	long long N, x; scanf("%lld %lld", &N, &x);

	long long sum = 0, Ai, I;
	for (int i = 0; i < N; i++) {
		scanf("%lld %lld", &Ai, &I);
		sum += Ai;
		sum *= x;
		sum %= MOD;
	}
	scanf("%lld %lld", &Ai, &I);
	sum += Ai;
	sum %= MOD;

	printf("%lld\n", sum);
}
