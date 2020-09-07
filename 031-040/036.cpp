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

VLL convertToBase(LL num, LL k) {
	VLL digits;
	while(num != 0) {
		digits.push_back(num % k);
		num /= k;
	}
	reverse(digits.begin(), digits.end());
	return digits;
}

bool isPalindrome(VLL digits) {
	rep(i, 0, digits.size()) {
		if(digits[i] != digits[digits.size()-i-1]) {
			return false;
		}
	}
	return true;
}

int main() {
	sll(n); sll(k);
	LL sum = 0;
	rep(i, 1, n+1) {
		if(isPalindrome(convertToBase(i, 10)) && isPalindrome(convertToBase(i, k))) {
			sum += i;
		}
	}
	pll(sum); nl;
}
