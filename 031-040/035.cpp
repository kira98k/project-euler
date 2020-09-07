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

const LL MAXN = 1e6+10;
bool isPrime[MAXN];
VLL primes;

void sieve() {
	rep(i, 0, (LL)MAXN) {
		isPrime[i] = (i > 1);
	}
	rep(p, 2, (LL)MAXN) {
		if(isPrime[p]) {
			primes.push_back(p);
			for(LL j = p * p; j < MAXN; j += p) {
				isPrime[j] = false;
			}
		}
	}
}

VLL getDigits(LL num) {
	VLL digits;
	while(num != 0) {
		digits.push_back(num%10);
		num /= 10;
	}
	reverse(digits.begin(), digits.end());
	return digits;
}

LL getNumber(VLL digits) {
	LL num = 0;
	rep(i, 0, digits.size()) {
		num = 10 * num + digits[i];
	}
	return num;
}

VLL getRotations(LL num) {
	VLL digits = getDigits(num);
	VLL rotations;
	rep(i, 0, digits.size()) {
		rotations.push_back(getNumber(digits));
		LL front = digits.front();
		digits.erase(digits.begin());
		digits.push_back(front);
	}
	return rotations;
} 

int main() {
	sieve();
	sll(n);
	LL sum = 0;
	for(LL prime : primes) {
		if(prime > n) {
			break;
		}
		VLL rotations = getRotations(prime);
		bool circular = true;
		rep(it, rotations.begin(), rotations.end()) {
			if(!isPrime[*it]) {
				circular = false;
				break;
			}
		}
		if(circular) {
			sum += prime;
		}
	}
	cout << sum << endl;
}
