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

const LL MAXN = 5e6 + 10;
LL collatzSteps[MAXN];
LL maxCollatzSteps[MAXN];

// Count number of steps for n
LL countCollatzSteps(LL n) { 
	LL steps = 0, start = n;
	// Loop until we get to 1
	while(n != 1) {
		// Calculate next number via the formula
		n = (n % 2 == 0 ? n / 2 : 3 * n + 1);
		steps++;
		// If we are in the limits and we have already calculated steps
		// Then add that to the current steps and exit
		if(n < MAXN && collatzSteps[n] != 0) {
			steps += collatzSteps[n];
			break;
		}
	}
	// Store the number of steps for the input
	collatzSteps[start] = steps;
	return steps;
}

void init() {
	rep(i, 0, (LL)MAXN) {
		collatzSteps[i] = maxCollatzSteps[i] = 0;
	}
	LL maxSteps = 0, maxNum = 0;
	rep(i, 1, (LL)MAXN) {
		LL steps = countCollatzSteps(i);
		// Keep track of the number with maximum steps until now
		if(steps >= maxSteps) {
			maxSteps = steps;
			maxNum = i;
		}
		// Store the number with maximum steps 
		maxCollatzSteps[i] = maxNum;
	}
}

int main() {
	init();
	sll(t);
	rep(_, 0, t) {
		sll(n);
		pll(maxCollatzSteps[n]); nl;
	}
}

