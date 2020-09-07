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

VLL getDigits(LL num) {
	VLL digits;
	while(num != 0) {
		digits.push_back(num%10);
		num /= 10;
	}
	reverse(digits.begin(), digits.end());
	return digits;
}

LL getNumberWithoutPositions(VLL digits, VLL positions) {
	LL num = 0;
	rep(i, 0, digits.size()) {
		if(find(positions.begin(), positions.end(), i) == positions.end()) {
			num = 10 * num + digits[i];
		}
	}
	return num;
}


map<multiset<LL>, set<PLL>> fraction_map;

set<PLL> selected;

int main() {
	sll(n); sll(k);
	LL num_sum = 0, den_sum = 0;
	
	// For every n digit number
	LL low = pow(10, n-1);
	LL high = pow(10, n);
	if(k == 1) {
		rep(x, low, high) {
			VLL digits = getDigits(x);
			// Select 1 digit to delete and store a pair of the number and the number after deleting the digit
			rep(i, 0, n) {
				fraction_map[{digits[i]}].insert({ x, getNumberWithoutPositions(digits, {i}) });
			}
		}
		// Select the deleted digit
		// Deleted digit can't be zero
		rep(d, 1, 10) {
			for(auto it : fraction_map[{d}]) {
				for(auto jt : fraction_map[{d}]) {
					// Compare each pair of numbers containing thhose digits
					if(it.first < jt.first 
						&& it.first * jt.second == it.second * jt.first
						&& it.second != 0 && jt.second != 0
						&& selected.find({it.first, jt.first}) == selected.end()) {
						// Add to result if not added before
						selected.insert({it.first, jt.first});
						num_sum += it.first;
						den_sum += jt.first;
					}
				}
			}
		}
	}
	else if(k == 2) {
		rep(x, low, high) {
			VLL digits = getDigits(x);
			// Select 2 digits to delete and store a pair of the number and the number after deleting the digit
			rep(i, 0, n) {
				rep(j, i+1, n) {
					fraction_map[{digits[i], digits[j]}].insert({ x, getNumberWithoutPositions(digits, {i, j}) });
				}
			}
		}
		// Select the deleted digits
		// Deleted digit can't be zero
		rep(d1, 1, 10) {
			rep(d2, d1, 10) {
				// Compare each pair of numbers containing thhose digits
				for(auto it : fraction_map[{d1, d2}]) {
					for(auto jt : fraction_map[{d1, d2}]) {
						if(it.first < jt.first 
							&& it.first * jt.second == it.second * jt.first
							&& it.second != 0 && jt.second != 0
							&& selected.find({it.first, jt.first}) == selected.end()) {
							// Add to result if not added before
							selected.insert({it.first, jt.first});
							num_sum += it.first;
							den_sum += jt.first;
						}
					}
				}
			}
		}
	}
	else if(k == 3) {
		rep(x, low, high) {
			VLL digits = getDigits(x);
			// Select 3 digits to delete and store a pair of the number and the number after deleting the digit
			rep(i, 0, n) {
				rep(j, i+1, n) {
					rep(k, j+1, n) {
						fraction_map[{digits[i], digits[j], digits[k]}].insert({ x, getNumberWithoutPositions(digits, {i, j, k}) });
					}
				}
			}
		}
		// Select the deleted digits
		// Deleted digit can't be zero
		rep(d1, 1, 10) {
			rep(d2, d1, 10) {
				rep(d3, d2, 10) {
					// Compare each pair of numbers containing thhose digits
					for(auto it : fraction_map[{d1, d2, d3}]) {
						for(auto jt : fraction_map[{d1, d2, d3}]) {
							if(it.first < jt.first 
								&& it.first * jt.second == it.second * jt.first
								&& it.second != 0 && jt.second != 0
								&& selected.find({it.first, jt.first}) == selected.end()) {
								// Add to result if not added before
								selected.insert({it.first, jt.first});
								num_sum += it.first;
								den_sum += jt.first;
							}
						}
					}
				}
			}
		}
	}
	pll(num_sum); pll(den_sum); nl;
}