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

const LL MAXN = 1e6 + 10;
bool isPrime[MAXN];
VLL primes;

// Calculate all primes upto 10^6 + 10
void sieve() {
    rep(i, 2, (LL) MAXN) {
        isPrime[i] = true;
    }
    rep(prime, 2, (LL) MAXN) {
        if(isPrime[prime]) {
            primes.push_back(prime);
            for (LL d = prime * prime; d < MAXN; d += prime) {
                isPrime[d] = false;
            }
        }
    }
}

int main() {
    sieve();
    sll(t);
    rep(_, 0, t) {
        sll(n);
        LL sum = 0;
        for(LL prime : primes) {
            if(prime <= n) {
                sum += prime;
            }
            else {
                break;
            }
        }
        pll(sum); nl;
    }
}
