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
	VLL bigints[n];
	rep(i, 0, n) {
		string s; cin >> s;
		// Reverse the string so that the lowest significat digit is first
		reverse(s.begin(), s.end());
		rep(j, 0, 50) {
			bigints[i].push_back(LL(s[j]-'0'));
		}
	}

	LL carry = 0;
	VLL bigsum;
	rep(i, 0, 50) {
		// Add all the ith digit of all the numbers
		LL sum = carry;
		rep(j, 0, n) {
			sum += bigints[j][i];
		}
		// Push one digit and pass others to carry over
		bigsum.push_back(sum % 10);
		carry = sum / 10;
	}
	// Add the digits in the remaining carry over
	while(carry != 0) {
		bigsum.push_back(carry % 10);
		carry = carry / 10;
	}
	rep(it, bigsum.rbegin(), bigsum.rbegin()+10) {
		cout << *it;
	}
	cout << endl;
}
