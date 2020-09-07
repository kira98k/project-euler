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

const LL MOD = 1e9 + 7;
const LL MAXN = 1e5+10;
const LL coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};


// ways[i][j] = Number of making j with first i coins
LL ways[9][MAXN];

// Precalculate ways 
void init() {
	rep(i, 0, 9) {
		rep(j, 0, (LL)MAXN) {
			ways[i][j] = 0;
		}
	}
	rep(i, 0, 9) {
		rep(j, 0, (LL)MAXN) {
			if(j == 0) {
				ways[i][j] = 1;
			}
			else if(i == 0) {
				ways[i][j] = 0;
			}
			else {
				ways[i][j] = ways[i-1][j];
				if(coins[i-1] <= j) {
					ways[i][j] += ways[i][j - coins[i-1]];
				}
				ways[i][j] %= MOD;
			}
		}
	}
}

int main() {
	init();
	sll(t);
	rep(_, 0, t) {
		sll(n);
		cout << ways[8][n] << endl;
	}
}