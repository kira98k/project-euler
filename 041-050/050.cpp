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

const LL MAXN = 7e6 + 10;
bool isPrime[MAXN];
VLL primes;
VLL primeSums;

void sieve() {
	rep(i, 0, (LL)MAXN) {
		isPrime[i] = (i > 1);
	}
	rep(p, 2, (LL)MAXN) {
		if(isPrime[p]) {
			primes.push_back(p);
			primeSums.push_back(p + (primeSums.empty() ? 0 : primeSums.back()));
			for(LL j = p*p; j < MAXN; j += p) {
				isPrime[j] = false;
			}
		}
	}
}

LL modmul(LL a, LL b, LL m) {
	LL r = 0;
	a = (a % m); b = (b % m);
	while(b != 0) {
		if(b%2 == 1) {
			r = (r + a) % m;
		}
		a = (a * 2) % m;
		b >>= 1;
	}
	return r;
}

LL modpow(LL a, LL n, LL m) {
	LL r = 1;
	a = (a % m);
	while(n != 0) {
		if(n%2 == 1) {
			r = modmul(r, a, m);
		}
		a = modmul(a, a, m);
		n >>= 1;
	}
	return r;
}

bool millerTest(LL d, LL n) {
	// Pick a random number in [2..n-2]
	// Corner cases make sure that n > 4
	LL a = 1 + (rand() % (n - 1));

	// Compute a^d % n
	LL x = modpow(a, d, n);

	if (x == 1 || x == n-1) {
		return true;
	}

	/* 
	Keep squaring x while one of the following doesn't happen
	1. d does not reach n-1
	2. (x^2) % n is not 1
	3. (x^2) % n is not n-1
	*/
	while (d != n-1) {
		x = modmul(x, x, n);
		d *= 2;

		if (x == 1) {
			return false;
		}
		if (x == n-1) {
			return true;
		}
	}

	// Return composite
	return false;
}

bool checkPrime(LL n) {
	if(n <= primes.back()) {
		return binary_search(primes.begin(), primes.end(), n);
	}
	// Find d such that n = 2^r * d + 1 for some r >= 0
	LL d = n - 1;
	while (d % 2 == 0) {
		d /= 2;
	}
	// Iterate given number of 5 times
	for (LL i = 0; i < 5; i++) {
		if (!millerTest(d, n)) {
			return false;
		}
	}
	return true;
}

LL getPrimeSum(LL start, LL end) {
	return primeSums[end] - (start > 0 ? primeSums[start - 1] : 0);
}

void solve(LL n) {
	LL sum = -1, length = -1;
	PLL range;
	rep(start, 0, 32) {
		LL lo = start, hi = start + 500000;
		while(lo < hi) {
			LL mid = (lo+hi+1)>>1;
			LL range_sum = getPrimeSum(start, mid);
			if(range_sum > n) hi = mid - 1;
			else lo = mid;
		}
		LL end = lo;
		while(!checkPrime(getPrimeSum(start, end))) {
			end--;
		}
		if((end-start+1) > length) {
			sum = getPrimeSum(start, end);
			length = end-start+1;
			range = {start, end};
		}
		else if((end-start+1) == length) {
			sum = min(sum, getPrimeSum(start, end));
			length = end-start+1;
			range = {start, end};
		}
	}
	pll(sum); pll(length); nl;
}

int main() {
	sieve();
	sll(t);
	rep(_, 0, t) {
		sll(n);
		solve(n);
	}
}
