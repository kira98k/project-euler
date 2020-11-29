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

typedef unsigned long long int ULL;
typedef long long int LL;
typedef long double LD;
typedef vector<LL> VLL;
typedef pair<LL, LL> PLL;

const ULL MOD = 1e10;

inline ULL modmul(ULL x, ULL y, ULL m) {
	if (x > (1<<30) && y > (1 << 30)) {
		return ((x >> 30)*((y << 30) % m) + y*(x & ((1 << 30) - 1))) % m;
	}
	ULL z = x*y;
	if (z >= m) {
		z %= m;
	}
	return z;
	
}

ULL modpow(ULL a, ULL n, ULL m) {
	ULL res = 1;
	while(n != 0) {
		if(n%2 == 1) {
			if( (((LD)res) * ((LD)a)) < 1e18 ) {
				res = (res*a)%m;
			}
			else {
				res = modmul(res, a, m);
			}
		}
		if( (((LD)a) * ((LD)a)) < 1e18) {
			a = (a*a) % m;
		}
		else {
			a = modmul(a, a, m);
		}
		n >>= 1;
	}
	return (res % m);
}

int main() {
	sll(n);
	LL ans = 0;
	rep(i, 1, n+1) {
		ans += modpow(i, i, MOD);
		ans %= MOD;
	}
	pll(ans); nl;
}
