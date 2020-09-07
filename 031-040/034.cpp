#include <bits/stdc++.h>
#include <climits>

// Loops from `begin` to `end` excluding `end`. Goes forward and backward both.
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
// Same as above. Only goes forward.
#define srep(i, begin, end) for (__typeof(end) i = begin; i != end; i++)
#define sll(x) LL x; cin >> x
#define pll(x) printf("%lld ", x)
#define nl printf("\n")

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef vector<LL> VLL;
typedef pair<LL, LL> PLL;

LL factorial(LL n) {
	if(n <= 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

bool isCurious(LL n) {
	LL sum = 0;
	LL temp = n;
	while(temp != 0) {
		sum += factorial(temp % 10);
		sum %= n;
		temp /= 10;
	}
	return (sum % n == 0);
}

int main() {
	sll(n);
	LL sum = 0;
	rep(i, 10, n+1) {
		if(isCurious(i)) {
			sum += i;
		}
	}
	cout << sum << endl;
}
