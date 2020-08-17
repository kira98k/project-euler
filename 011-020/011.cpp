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

// Check Up-Down
LL checkUpDown(LL grid[20][20]) {
	LL maxProduct = -1;
	rep(column, 0, 20) {
		rep(row, 0, 17) {
			LL product = 1;
			rep(i, 0, 4) {
				product *= grid[row+i][column];
			}
			maxProduct = max(maxProduct, product);
		}
	}
	return maxProduct;
}

// Check Left-Right
LL checkLeftRight(LL grid[20][20]) {
	LL maxProduct = -1;
	rep(row, 0, 20) {
		rep(column, 0, 17) {
			LL product = 1;
			rep(i, 0, 4) {
				product *= grid[row][column+i];
			}
			maxProduct = max(maxProduct, product);
		}
	}
	return maxProduct;
}

// Check Diagonal
LL checkDiagonal(LL grid[20][20]) {
	LL maxProduct = -1;
	// Left to Right Diagonal
	rep(row, 0, 17) {
		rep(column, 0, 17) {
			LL product = 1;
			rep(i, 0, 4) {
				product *= grid[row+i][column+i];
			}
			maxProduct = max(maxProduct, product);
		}
	}

	// Right to Left Diagonal
	rep(row, 0, 17) {
		rep(column, 3, 20) {
			LL product = 1;
			rep(i, 0, 4) {
				product *= grid[row+i][column-i];
			}
			maxProduct = max(maxProduct, product);
		}
	}

	return maxProduct;
}

int main() {
	LL grid[20][20];
	rep(i, 0, 20) {
		rep(j, 0, 20) {
			cin >> grid[i][j];
		}
	}
	LL maxUpDown = checkUpDown(grid);
	LL maxLeftRight = checkLeftRight(grid);
	LL maxDiagonal = checkDiagonal(grid);
	LL maxProduct = max(maxDiagonal, max(maxUpDown, maxLeftRight));
	pll(maxProduct); nl;
}
