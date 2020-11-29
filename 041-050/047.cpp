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


const LL MAXN = 2e6+10;
// Lowest Prime Divisors
LL lpd[MAXN];
// Distinct Prime Divisors
LL dpd[MAXN];
VLL primes;

void sieve() {
	rep(i, 0, (LL) MAXN) {
		lpd[i] = i;
	}
	rep(prime, 2, (LL) MAXN) {
		if(lpd[prime] == prime) {
			primes.push_back(prime);
			for (LL d = prime * prime; d < MAXN; d += prime) {
				lpd[d] = prime;
			}
		}
	}
	dpd[1] = 0;
	rep(i, 2, (LL)MAXN) {
		LL p = lpd[i], n = i;
		while(n % p == 0) {
			n /= p;
		}
		dpd[i] = 1 + dpd[n];
	}
}

int main() {
	sieve();
	sll(n); sll(k);
	rep(i, 2, n+1) {
		bool allowed = true;
		rep(x, i, i+k) {
			if(dpd[x] != k) {
				allowed = false;
			}
		}
		if(allowed) {
			pll(i); nl;
		}
	}
}
