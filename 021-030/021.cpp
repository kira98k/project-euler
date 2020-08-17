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

const LL MAXN = 1e6+10;
LL lpd[MAXN], sum_of_divisors[MAXN];

// Calculate Lowest Prime Divisor Of Each Number
void sieve() {
	rep(i, 0, (LL)MAXN) lpd[i] = i;
	rep(prime, 2, (LL)MAXN) {
		if(lpd[prime] == prime) {
			for(LL d = prime * prime; d < MAXN; d += prime) {
				lpd[d] = prime;
			}
		}
	}
}

// Calculate and store the sum of divisors of each number
void init() {
	sieve();
	rep(x, 1, (LL)MAXN) {
		if(x == 1) {
			sum_of_divisors[x] = 1;
		}
		else {
			LL prime = lpd[x];
			LL count = 0, number = x;
			while(number % prime == 0) {
				count++;
				number /= prime;
			}
			// Sum of divisors of (n * p^k) = sum of divisors of n * (p^(k+1)-1)/(p-1)
			// where p is a prime and p does not divide n 
			sum_of_divisors[x] = sum_of_divisors[number] * ((LL)(pow(prime, count+1)-1)/(prime-1));
		}
	}
}

int main() {
	init();
	sll(t);
	rep(_, 0, t) {
		sll(n);
		LL answer = 0;
		rep(a, 1, n+1) {
			// b = Sum of proper divisors of a
			LL b = sum_of_divisors[a] - a;
			// Add only a as b will be added later
			if(a != b && a == sum_of_divisors[b] - b) {
				answer += a;
			}
		}
		pll(answer); nl;
	}
}
