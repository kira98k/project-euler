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

int main() {
	sll(t);
	rep(_, 0, t) {
		sll(n);
		VLL prime_factors;
		// The smallest factor greater than 1 of any number is always a prime
		// Keep dividing by its smallest factors that are less than sqrt(n)
		for(LL prime = 2; prime * prime <= n; prime++) {
			// Keep dividing until it is divisible
			while(n % prime == 0) {
				n = n / prime;
				prime_factors.push_back(prime);
			}
		}
		// If there are no such factors then remaining n must be prime itself
		if(n != 1) {
			prime_factors.push_back(n);
		}
		// Take the maximum of all prime factors
		pll(*max_element(prime_factors.begin(), prime_factors.end())); nl;
	}
}
