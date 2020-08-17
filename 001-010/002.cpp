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
		LL sum = 0;
		LL current = 1, next = 2;
		while(current <= n) {
			// If even add to the sum
			if(current % 2 == 0) {
				sum += current;
			}
			// Next number is the sum of the previous two numbers
			LL next_to_next = current +  next;
			current = next;
			next = next_to_next;
		}
		pll(sum); nl;
	}
}
