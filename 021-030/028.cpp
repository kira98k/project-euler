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

const LL MOD = 1e9+7;

// Modular Inverses
const LL MODINV2 = 500000004;
const LL MODINV3 = 333333336;

/* Formula :

(x^2-x+1) . . x^2 
. . . . . . . 
(x^2-2x+2) . (x^2-3x+3)

Given n is odd
Answer = Sum( 4x^2 - 6x + 6 for x = 1 to n when x is odd) - 3
Subtracting 3 as we're counting 1 at the center four times

Answer = 4 * n(n+1)(n+2) / 6 - 6*(n+1)*(n+1) / 4 + 6*(n+1)/2 - 3

*/


// Modular Multiplication
LL modmul(VLL nums, LL m) {
    LL r = 1;
    for(LL num : nums) {
        r = (r * (num % m)) % m;
    }
    return (r%m);
}

int main() {
    sll(t);
    rep(_, 0, t) {
        sll(n);
        LL sum = ( modmul({2, n, n+1, n+2, MODINV3}, MOD) 
                - modmul({3, n+1, n+1, MODINV2}, MOD) + modmul({3, n+1}, MOD) - 3 ) % MOD;
        while(sum < 0) {
            sum += MOD;
        }
        pll(sum); nl;
    }
}
