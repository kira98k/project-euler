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
        VLL curr;
        rep(i, 1, n+1) {
            VLL next(i);
            rep(j, 0, i) {
                cin >> next[j];
                // Add maximum curr[j] and curr[j-1] to next[j] if they exist
                // Because the numbers can either go down or down-right
                if(i > 1) {
                    if(j == 0) {
                        next[j] += curr[j];
                    }
                    else if(j == i-1) {
                        next[j] += curr[j-1];
                    }
                    else {
                        next[j] += max(curr[j], curr[j-1]);
                    }
                }
            }
            curr = next;
        }
        // Take the maxmimum present sum
        pll(*max_element(curr.begin(), curr.end())); nl;
    }
}
