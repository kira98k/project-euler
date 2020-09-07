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

typedef unsigned long long int ULL;
typedef long long int LL;
typedef long double LD;
typedef vector<LL> VLL;
typedef pair<LL, LL> PLL;

ULL digits[18];
ULL positions[18];

ULL fastpow(ULL a, ULL n) {
	ULL res = 1;
	while(n != 0) {
		if(n&1 != 0) {
			res *= a;
		}
		a = a*a;
		n >>= 1;
	}
	return res;
}

void init() {
	rep(i, (ULL)0, (ULL)18) {
		if(i == 0) {
			digits[i] = 0;
			positions[i] = 1;
		}
		else {
			digits[i] = (9 * fastpow((ULL)10, i-1) * i + digits[i-1]);
			positions[i] = (9 * fastpow((ULL)10, i-1) + positions[i-1]);
		}
	}
}

ULL getNthDigit(LL n) {
	ULL digit = upper_bound(digits, digits+18, n) - digits;
	ULL position = positions[digit-1];
	n -= digits[digit-1];
	position += (n / digit);
	n %= digit;

	string number = to_string(position);
	return (number[n] - '0');
}

int main() {
	init();
	sll(t);
	rep(_, 0, t) {
		ULL product = 1;
		rep(i, 0, 7) {
			sll(n);
			product *= getNthDigit(n-1);
		}
		cout << product << endl;
	}
}
