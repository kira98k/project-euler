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

const LL MAXN = 5e5+10;
bool isPrime[MAXN];
VLL primes;

void sieve() {
	rep(i, 0, (LL) MAXN) {
		isPrime[i] = (i > 1);
	}
	rep(prime, 2, (LL) MAXN) {
		if(isPrime[prime]) {
			primes.push_back(prime);
			for (LL d = prime * prime; d < MAXN; d += prime) {
				isPrime[d] = false;
			}
		}
	}
}

bool isPerfectSquare(LL n) {
	LL x = sqrt(n);
	return (x*x == n);
}

int main() {
	sieve();
	sll(t);
	rep(_, 0, t) {
		sll(n);
		LL ans = 0;
		for(LL p: primes) {
			if(p > n) {
				break;
			}
			if(p == 2) {
				continue;
			}
			LL x = (n - p) / 2;
			if(isPerfectSquare(x)) {
				ans++;
			}
		}
		pll(ans); nl;
	}
}
