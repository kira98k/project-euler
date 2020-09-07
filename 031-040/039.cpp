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

const LL MAXN = 5e6+10;
LL solutions[MAXN];
LL maxSolutions[MAXN];

LL gcd(LL a, LL b) {
	if(b == 0) {
		 return a;
	}
	return gcd(b, a % b);
}

void init() {
	rep(x, 1, (LL)MAXN) {
		if(2*x*x > MAXN) {
			break;
		}
		rep(y, 1, x) {
			LL a = 2*x*y, b = x*x - y*y, c = x*x + y*y;
			LL p = 2*x*x + 2*x*y;
			if(gcd(gcd(a, b), c) != 1) {
				continue;
			}
			LL k = 1;
			while(k*p <= MAXN) {
				solutions[k*p]++;
				k++;
			}
		}
	}
	LL maxPos = 1;
	rep(i, 1, (LL)MAXN) {
		if(solutions[i] > solutions[maxPos]) {
			maxPos = i;
		}
		maxSolutions[i] = maxPos;
	}
}

// Every pythogorean triplet is of the form
// { 2xy, x^2 - y^2, x^2 + y^2 }
// or an integer multiple of such a form
int main() {
	init();
	sll(t);
	rep(_, 0, t) {
		sll(n);
		pll(maxSolutions[n]); nl;
	}
}
