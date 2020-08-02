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

map<PLL, LL> cache;

// Calculate n choose r modulo MOD
LL nCr(LL n, LL r) {
    // n choose r == n choose (n-r)
    if(n - r < r) {
        r = n - r;
    }
    // Read from cache if available
    if(cache[make_pair(n, r)] != 0) {
        return cache[make_pair(n, r)];
    }
    LL answer;

    // Trivial Cases
    if(r == 0) {
        answer = 1;
    }
    else if(r == 1) {
        answer = n;
    }
    else {
        // Reduction formula for combinations
        answer = ( nCr(n-1, r) + nCr(n-1, r-1) ) % MOD;
    }
    // Store in cache
    cache[make_pair(n, r)] = answer;
    return answer;
}

int main() {
    sll(t);
    rep(_, 0, t) {
        sll(n); sll(m);
        pll(nCr(n+m, n)); nl;
    }
}
