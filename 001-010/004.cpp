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

// Check if a palindrome
bool isPalindrome(LL n) {
    VLL digits;
    while(n != 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    rep(i, 0, (LL)digits.size()) {
        if(digits[i] != digits[digits.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

// Check if a product of two 3-digit numbers
bool isProductOfTwo3DigitNumbers(LL n) {
    rep(x, 100, 1000) {
        if(n % x == 0 && (n/x) >= 100 && (n/x) < 1000) {
            return true;
        }
    }
    return false;
}

int main() {
    sll(t);
    rep(_, 0, t) {
        sll(n);
        while(true) {
            // must be less than n so don't check n
            n -= 1;
            // If both conditions satisfy then we found the answer
            if(isPalindrome(n) && isProductOfTwo3DigitNumbers(n)) {
                break;
            }
            
        }
        pll(n); nl;
    }
}
