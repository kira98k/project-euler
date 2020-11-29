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

VLL primes = {1, 2, 3, 5, 7, 11, 13, 17, 23};

int main() {
	sll(n);
	VLL digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	digits.resize(n+1);
	LL sum = 0;
	do {
		bool allowed = true;
		rep(i, 0, n-1) {
			LL number = digits[i] * 100 + digits[i+1] * 10 + digits[i+2];
			if(number % primes[i] != 0) {
				allowed = false;
				break;
			}
		}
		LL number = 0;
		rep(i, 0, n+1) {
			number = 10 * number + digits[i];
		}
		if(allowed) {
			sum += number;
		}
	} while(next_permutation(digits.begin(), digits.end()));
	pll(sum); nl;
}
