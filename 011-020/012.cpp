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

const LL MAXN = 1e6+10;
// lpd[i] = lowest prime divisor of i
LL lpd[MAXN];
// divisors[i] = number of divisors of i
LL divisors[MAXN];

// Calculate lpd array
void sieve() {
    rep(i, 0, (LL)MAXN) {
        lpd[i] = i;
    }
    rep(prime, 2, (LL)MAXN) {
        if(lpd[prime] == prime) {
            for(LL d = prime * prime; d < MAXN; d += prime) {
                lpd[d] = prime;
            }
        }
    }
}

// Count Number of Divisors of number
LL countDivisors(LL number) {
    if(divisors[number] != 0) {
        return divisors[number];
    }
    divisors[number] = 1;
    LL temp = number;
    while(temp != 1) {
        LL prime = lpd[temp];
        LL count = 0;
        while(temp % prime == 0) {
            temp /= prime;
            count++;
        }
        divisors[number] *= (count + 1);
    }
    return divisors[number];
}

// Power of 2 in factorization of number
LL getPowerOf2(LL number) {
    LL count = 0;
    while(number % 2 == 0) {
        number /= 2;
        count++;
    }
    return count;
}

// Count Divisors of nth triangular number
LL countDivisorsOfNthTriangularNumber(LL n) {
    LL divisors = countDivisors(n) * countDivisors(n + 1);
    LL power_of_2 = getPowerOf2(n) + getPowerOf2(n + 1);
    
    // Dividing by two causes the count of power of 2 to decrease by 1
    divisors = divisors * power_of_2 / (power_of_2 + 1); 
    return divisors;
}


int main() {
    sieve();
    sll(t);
    rep(_, 0, t) {
        sll(n);
        LL x = 1;
        while(countDivisorsOfNthTriangularNumber(x) <= n) {
            x++;
        }
        pll(x * (x + 1) / 2); nl;
    }
}
