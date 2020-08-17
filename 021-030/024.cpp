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

LL factorials[14] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 
						3628800, 39916800, 479001600, 6227020800 };

int main() {
	sll(t);
	rep(_, 0, t) {
		string s = "abcdefghijklm";
		sll(n);
		// n = l! then just reverse the string
		if(n == factorials[s.length()]) {
			reverse(s.begin(), s.end());
			cout << s << endl;
			continue;
		}
		rep(f, (LL)s.length(), 2) {
			// Moving to f! position
			while(n >= factorials[f]) {
				// Moving from position x to position (x + f! - 1)
				reverse(s.begin() + (s.length() - f) , s.end());
				n -= (factorials[f] - 1);
				// Moving to position x + f!
				if(n > 1) {
					next_permutation(s.begin(), s.end());
					n -= 1;
				}
			}
		}
		
		cout << s << endl;
	}
}
