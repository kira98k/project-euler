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

const LL MAXN = 1e4+10;
LL sum_of_digits[MAXN];

void init() {
    // Denoting the number 1 by an array
    VLL bignum;
    bignum.push_back(1);
    rep(i, 1, (LL)MAXN) {
        LL carry = 0;
        rep(j, 0, bignum.size()) {
            bignum[j] = 2 * bignum[j] + carry;
            carry = bignum[j] / 10;
            bignum[j] %= 10;
        }
        while(carry != 0) {
            bignum.push_back(carry % 10);
            carry /= 10;
        }
        sum_of_digits[i] = accumulate(bignum.begin(), bignum.end(), 0);
    }
}

int main() {
    init();
    sll(t);
    rep(_, 0, t) {
        sll(n);
        pll(sum_of_digits[n]); nl;
    }
}
