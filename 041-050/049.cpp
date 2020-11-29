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
			for(LL j = p*p; j < MAXN; j += p) {
				isPrime[j] = false;
			}
		}
	}
}

VLL getDigits(LL n) {
	VLL digits;
	while(n != 0) {
		digits.push_back(n%10);
		n /= 10;
	}
	reverse(digits.begin(), digits.end());
	return digits;
}

LL getNumber(VLL digits) {
	LL result = 0;
	for(LL digit : digits) {
		result = 10 * result + digit;
	}
	return result;
}

VLL getPrimePermutations(LL n) {
	VLL primePermutations;
	VLL digits = getDigits(n);
	do {
		LL number = getNumber(digits);
		if(isPrime[number]) {
			primePermutations.push_back(number);
		}
	} while(next_permutation(digits.begin(), digits.end()));
	return primePermutations;
}

// Give a sorted array to find AP of size 3 or 4
vector<VLL> findArithmeticProgression(VLL numbers, LL size) {
	vector<VLL> aps;
	if(((LL)numbers.size()) < size) {
		return aps;
	}
	if(size == 3) {
		LL start = numbers[0];
		rep(i, 1, numbers.size()) {
			LL diff = numbers[i] - start;
			LL next = numbers[i] + diff;
			if(binary_search(numbers.begin(), numbers.end(), next)) {
				VLL ap;
				ap.push_back(start);
				ap.push_back(numbers[i]);
				ap.push_back(next);
				aps.push_back(ap);
			}
		}
	}
	if(size == 4) {
		LL start = numbers[0];
		rep(i, 1, numbers.size()) {
			LL diff = numbers[i] - start;
			LL next = numbers[i] + diff;
			if(binary_search(numbers.begin(), numbers.end(), next)) {
				if(binary_search(numbers.begin(), numbers.end(), next + diff)) {
					VLL ap;
					ap.push_back(start);
					ap.push_back(numbers[i]);
					ap.push_back(next);
					ap.push_back(next+diff);
					aps.push_back(ap);
				}
			}
		}
	}
	return aps;
}


int main() {
	sieve();
	sll(n); sll(k);
	map<LL, bool> seen;
	for(LL prime : primes) {
		if(prime < 1000) {
			continue;
		}
		if(prime > n) {
			break;
		}
		VLL primePermutations = getPrimePermutations(prime);

		vector<VLL> aps = findArithmeticProgression(primePermutations, k);
		for(VLL ap : aps) {
			if((LL)ap.size() == k) {
				for(LL number : ap) {
					cout << number;
				} nl;
			}
		}
	}
}
