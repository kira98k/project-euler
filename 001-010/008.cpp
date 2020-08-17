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
		sll(n); sll(k);
		string str; cin >> str;
		LL maxProduct = 0;
		rep(i, 0, n) {
			// Take product only if the kth digit is present
			if(i + k - 1 < n) {
				LL product = 1;
				// Take product for k digist starting at i
				rep(j, i, i+k) {
					LL digit = LL(str[j] - '0');
					product *= digit;
				}
				// Store the maximum of the products
				maxProduct = max(maxProduct, product);
			}
		}
		pll(maxProduct); nl;
	}
}
