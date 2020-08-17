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

const LL MAXN = 1e6 + 10;
bool isPrime[MAXN];
VLL primes;

void sieve() {
	rep(i, 0, (LL)MAXN) {
		isPrime[i] = true;
	}
	isPrime[0] = isPrime[1] = false;
	rep(p, 2, (LL)MAXN) {
		if(isPrime[p]) {
			for(LL j = p*p; j < MAXN; j += p) {
				isPrime[j] = false;
			}
		}
	}
}

bool checkIfPrime(LL n) {
	if(n < 2) {
		return false;
	}
	if(n < MAXN) {
		return isPrime[n];
	}
	for(LL p : primes) {
		if(n % p == 0) {
			return false;
		}
	}
	return true;
}

LL countPrimeSequence(LL a, LL b) {
	LL x = 0;
	while(checkIfPrime(x*x + a*x + b)) {
		x++;
	}
	return x;
}

int main() {
	sieve();
	sll(n);
	LL maxCount = 0;
	PLL pair;
	rep(a, -n, n+1) {
		rep(b, -n, n+1) {
			LL count = countPrimeSequence(a, b);
			if(count > maxCount) {
				maxCount = count;
				pair = make_pair(a, b);
			}
		}
	}
	pll(pair.first); pll(pair.second); nl;
}
