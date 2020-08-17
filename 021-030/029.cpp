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

const LL MAXN = 1e5+10;
PLL purePower[MAXN];

// purePower[n] = (p, x) then n = p^x
void init() {
	rep(i, 0, (LL)MAXN) {
		purePower[i] = make_pair(-1, -1);
	}
	rep(p, 2, (LL)MAXN) {
		LL x = p, cnt = 1;
		while(x < MAXN) {
			x *= p;
			cnt++;
			if(x < MAXN && purePower[x].first == -1) {
				purePower[x] = make_pair(p, cnt);
			}
		}
	}
}

int main() {
	init();
	sll(n);
	// Maximum b such that a^b <= n for some a
	LL maxPower = floor(log2(n));
	// uniques[i] = Number of unique numbers 
	// in the multiplication table of size i*n
	// starting from multiplication by 2.
	LL uniques[maxPower+1];
	set<LL> numbers;
	rep(i, 1, maxPower+1) {
		rep(j, 2, n+1) {
			numbers.insert(i*j);
		}
		uniques[i] = numbers.size();
	}
	LL ans = 0;
	rep(i, 2, n+1) {
		if(purePower[i].first == -1) {
			LL maxPower = (log10(n) / log10(i));
			cout << i << " " << maxPower << " " << uniques[maxPower] << endl;
			ans += uniques[maxPower];
		}
	}
	cout << ans << endl;
}
