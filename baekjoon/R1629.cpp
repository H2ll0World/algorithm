/*
	1629 곱셈
 	시간복잡도 O(logN)
*/

#include <iostream>

using namespace std;
using ll = long long;
ll pow(ll a, ll b, ll c) {
	if (b == 1) return a % c;
	ll val = pow(a, b / 2, c);
	val = val * val % c;
	if (b % 2 == 0) return val % c;
	return val * a % c;
}

int main() {
	long long A, B, C, result = 1;
	cin >> A >> B >> C;
	
	cout << pow(A, B, C);

	return 0;
}
