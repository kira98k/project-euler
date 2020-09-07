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

VLL getDigits(LL num) {
	VLL digits;
	while(num != 0) {
		digits.push_back(num % 10);
		num /= 10;
	}
	return digits;
}

bool isMultiplier(LL n, LL k) {
	set<LL> seen;
	rep(i, 1, 10) {
		VLL digits = getDigits(i * n);
		for(LL digit: digits) {
			if(seen.find(digit) != seen.end()) {
				return false;
			}
			seen.insert(digit);
		}
		if(seen.find(0) != seen.end()) {
			return false;
		}
		if(k == 8 && seen.find(9) != seen.end()) {
			return false;
		}
		bool all = true;
		rep(i, 1, k+1) {
			if(seen.find(i) == seen.end()) {
				all = false;
				break;
			}
		}
		if(all) {
			return true;
		}
	}
	return false;
}

int main() {
	sll(n); sll(k);
	rep(i, 2, n+1) {
		if(isMultiplier(i, k)) {
			pll(i); nl;
		}
	}
}
