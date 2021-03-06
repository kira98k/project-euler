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
		LL sum_of_squares = n * (n + 1) * (2 * n + 1) / 6;
		LL square_of_sum = (n * (n + 1) / 2) * (n * (n + 1) / 2);
		pll(abs(sum_of_squares - square_of_sum)); nl;
	}
}
