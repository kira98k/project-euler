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

/*
Given: 
1. a + b + c = n 
2. a * a + b * b = c * c
Assume some value of a.

Now, c * c - b * b = a * a
	=> (c - b) * (c + b) = a * a
	=> (c - b) * (n - a) = a * a    (From Equation 1)
	=> c - b = a * a / (n - a)      [Equation 3]

Subtracting Equation 3 from Equation 1, 
	=>  a + 2 * b = n -  a * a / (n - a)
	=>  2 * b = (n - a) - a * a / (n - a)
	=> 2 * b = [(n - a) * (n - a) - a * a] / (n - a)
	=> b = (n * n - 2 * a * n) / (2 * n - 2 * a)    [Equation 4]
*/

int main() {
	sll(t);
	rep(_, 0, t) {
		sll(n);
		LL maxProduct = -1;
		rep(a, 1, n) {
			// From Equation 4
			LL b = (n * n - 2 * a * n) / (2 * n - 2 * a);
			// From Equation 1
			LL c = n - a - b;
			if(a < b && b < c && a * a + b * b == c * c) {
				maxProduct = max(maxProduct, a * b * c);
			} 
		}
		pll(maxProduct); nl;
	}
}
