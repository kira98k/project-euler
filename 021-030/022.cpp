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

LL getNameValue(string s) {
    LL value = 0;
    for(char c : s) {
        value += (c - 'A') + 1;
    }
    return value;
}

int main() {
    sll(n);
    vector<string> names;
    rep(i, 0, n) {
        string name;
        cin >> name;
        names.push_back(name); 
    }
    // Sort names in alphabetical order
    sort(names.begin(), names.end());
    // Store position of each name of look up faster
    map<string, LL> positions;
    rep(i, 0, n) {
        positions[names[i]] = i + 1;
    }
    // Queries
    sll(q);
    rep(i, 0, q) {
        string query; 
        cin >> query;
        LL value = getNameValue(query);
        LL position = positions[query];
        LL score = value * position;
        pll(score); nl;
    }

}
