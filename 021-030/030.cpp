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

const LL MAXN = 4e6;

bool check(LL number, LL power) {
    LL sum = 0;
    LL x = number;
    while(x != 0) {
        LL digit = x%10;
        sum += (LL)pow(digit, power);
        x /= 10;
    }
    return (sum == number);
}

int main() {
    sll(n);
    LL sum = 0;
    rep(i, 2, (LL)MAXN) {
        if(check(i, n)) {
            sum += i;
        }
    }
    cout << sum << endl;
}
