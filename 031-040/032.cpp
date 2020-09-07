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
	sll(n);
	VLL digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	digits.resize(n);
	set<LL> nums;
	do {
		rep(a, 0, n) {
			rep(b, a+1, n-1) {
				LL A = 0, B = 0, C = 0;
				rep(i, 0, n) {
					if(i <= a) {
						A = 10*A + digits[i];
					}
					else if(i <= b) {
						B = 10*B + digits[i];
					}
					else {
						C = 10*C + digits[i];
					}
				}
				if(A*B == C) {
					nums.insert(C);
				}
			}
		}
	} while(next_permutation(digits.begin(), digits.end()));
	cout << accumulate(nums.begin(), nums.end(), 0) << endl;
}
