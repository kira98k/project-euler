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

LL pentagonal(LL n) {
	return n * (3*n - 1) / 2;
}

bool isPentagonal(LL n) {
	// 3x^2 - x = 2n
	LL x = ( sqrt(1+24*n) + 1 ) / 6;
	return (pentagonal(x) == n);
}

int main() {
	sll(n); sll(k);
	rep(i, k+1, n+1) {
		if(isPentagonal(pentagonal(i) - pentagonal(i-k)) 
		|| isPentagonal(pentagonal(i) + pentagonal(i-k))) {
			pll(pentagonal(i)); nl;
		}
	}
}
