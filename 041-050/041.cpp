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

const LL MAXN = 1e5+10;
bool isPrime[MAXN];
VLL primes;

void sieve() {
	rep(i, 0, (LL)MAXN) {
		isPrime[i] = (i > 1);
	}
	rep(p, 2, (LL)MAXN) {
		if(isPrime[p]) {
			primes.push_back(p);
			for(LL j = p*p; j < MAXN; j += p) {
				isPrime[j] = false;
			}
		}
	}
}

bool checkPrime(LL n) {
	if(n < MAXN) {
		return isPrime[n];
	}
	for(LL prime : primes) {
		if(n % prime == 0) {
			return false;
		}
	}
	return true;
}

VLL pandigitalPrimes;

void init() {
	sieve();
	rep(d, 4, 8) {
		VLL digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		digits.resize(d);
		do {
			LL number = 0;
			for(LL digit : digits) {
				number = 10 * number + digit;
			}
			if(checkPrime(number)) {
				pandigitalPrimes.push_back(number);
			}
		} while(next_permutation(digits.begin(), digits.end()));
	}
}

int main() {
	init();
	sll(t);
	rep(_, 0, t) {
		sll(n);
		LL pos = upper_bound(pandigitalPrimes.begin(), pandigitalPrimes.end(), n) - pandigitalPrimes.begin() - 1;
		if(pos == -1) {
			cout << -1 << endl;
		} else {
			cout << pandigitalPrimes[pos] << endl;
		}
	}
}
