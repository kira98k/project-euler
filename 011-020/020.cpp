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

// Using array as a number where bignum[i] denots the ith place digit
LL sumOfDigitsOfFactorial(LL n) {
	VLL bignum(1, 1);
	rep(i, 1, n+1) {
		LL carry = 0;
		rep(it, bignum.begin(), bignum.end()) {
			LL digit = (*it) * i + carry;
			*it = digit % 10;
			carry = digit / 10;
		}
		while(carry != 0) {
			bignum.push_back(carry % 10);
			carry /= 10;
		}
	}
	return accumulate(bignum.begin(), bignum.end(), 0);
}

int main() {
	sll(t);
	rep(_, 0, t) {
		sll(n);
		pll(sumOfDigitsOfFactorial(n)); nl;
	}
}
