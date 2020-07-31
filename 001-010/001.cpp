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

int main() {
    sll(t);
    rep(_, 0, t) {
        sll(n);
        // n - 1 because we need to exclude n itself
        LL multiples_of_3 = ((n - 1) / 3);
        LL multiples_of_5 = ((n - 1) / 5);
        LL multiples_of_15 = ((n - 1) / 15);
        // Multiples of 15 are counted twice so they are excluded once.
        LL sum = 3 * (multiples_of_3 * (multiples_of_3 + 1) / 2)
                + 5 * (multiples_of_5 * (multiples_of_5 + 1) / 2)
                - 15 * (multiples_of_15 * (multiples_of_15 + 1) / 2);
        pll(sum); nl;
    }
}
