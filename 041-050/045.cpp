#include <bits/stdc++.h>
#include <climits>

// Loops from `begin` to `end` excluding `end`. Goes forward and backward both.
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
// Same as above. Only goes forward.
#define srep(i, begin, end) for (__typeof(end) i = begin; i != end; i++)
#define sll(x) LL x; scanf("%lld", &x)
#define pll(x) printf("%lld ", x)
#define nl printf("\n")

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef vector<LL> VLL;
typedef pair<LL, LL> PLL;

bool isTriangular(LL n) {
	// x*x + x - 2n = 0
	LL x = (sqrt(1 + 8*n) - 1) / 2;
	return (x * (x+1) / 2 == n);
}

bool isPentagonal(LL n) {
	// 3x^2 - x - 2n = 0
	LL x = (sqrt(1 + 24 * n) + 1) / 6;
	return (x * (3*x - 1) / 2 == n);
}

int main() {
	sll(n); sll(a); sll(b);
	if(b == 6 && a == 5) {
		LL x = 1;
		while(x*(2*x-1) < n) {
			if(isPentagonal(x*(2*x-1))) {
				pll(x*(2*x-1)); nl;
			}
			x++;
		}
	}
	else if(b == 6 && a == 3) {
		LL x = 1;
		while(x*(2*x-1) < n) {
			if(isTriangular(x*(2*x-1))) {
				pll(x*(2*x-1)); nl;
			}
			x++;
		}
	}
	else if(b == 5 && a == 3) {
		LL x = 1;
		while(x*(3*x-1)/2 < n) {
			if(isTriangular(x*(3*x-1)/2)) {
				pll(x*(3*x-1)/2); nl;
			}
			x++;
		}
	}
}
