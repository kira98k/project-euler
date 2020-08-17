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

// Greatest Common Divisor
LL gcd(LL a, LL b) {
	if(a == 0) {
		return b;
	}
	return gcd(b % a, a);
}

// Lowest Common Multiple 
LL lcm(LL a, LL b) {
	LL g = gcd(a, b);
	return (a * b / g);
}

int main() {
	sll(t);
	rep(_, 0, t) {
		sll(n);
		LL l = 1;
		// Find Lowest Common Multiple of numbers from 1 to n
		rep(i, 1, n+1) {
			l = lcm(l, i);
		}
		pll(l); nl;
	}
}
