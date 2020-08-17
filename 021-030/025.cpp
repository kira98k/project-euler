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

const LD PHI = 1.618033988749895;
const LD phi = -0.6180339887498949;

const LL MAXN = 24010;
LL digits[MAXN];

// F(n) = (PHI^n - phi^n) / sqrt(5)
// At n > 20, we can ignore the contribution of phi^n
// Number of digits in x = floor( log10(x) + 1 )
LL getDigits(LL n) {
    if(n <= 20) {
        LL a = 0, b = 1;
        rep(i, 0, n) {
            LL tmp = a+b;
            a = b;
            b = tmp;
        }
        return (LL)(log10(a)+1);
    }
    return (LL)(n * log10(PHI) -  log10(5) / 2.0 + 1);
}

void init() {
    rep(n, 1, (LL)MAXN) {
        digits[n] = getDigits(n);
    }
}

int main() {
    init();
    sll(t);
    rep(_, 0, t) {
        sll(n);
        LL position = lower_bound(digits+1, digits+MAXN, n) - digits;
        cout << position << endl;
    }
}
