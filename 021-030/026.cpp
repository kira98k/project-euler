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

const LL MAXN = 1e4 + 10;

LL digits[MAXN];

// Number of repeating digits in 1/d is the number of digits in
// the smallest number of the form '9999...' that is divisible by d
// 2 and 5 do not add anything to the repetition of digits
void init() {
	rep(n, 0, (LL)MAXN) {
		if(n <= 2 || n == 5) {
			digits[n] = 0;
		}
		else if(n % 2 == 0) {
			digits[n] = digits[n/2];
		}
		else if(n % 5 == 0) {
			digits[n] = digits[n/5];
		}
		else {
			LL x = 10, p = 1;
			while(x%n != 1) {
				x = (x * 10) % n;
				p++;
			}
			digits[n] = p;
		}
	}
}

int main() {
	init();
	sll(t);
	rep(_, 0, t) {
		sll(n);
		LL position = max_element(digits+2, digits+n) - digits;
		pll(position); nl;
	}
}
