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

string ones[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string hundred = "Hundred";
string thousand = "Thousand";
string million = "Million";
string billion = "Billion";
string trillion = "Trillion";

// Convert Tens to Words
vector<string> convertTens(LL n) {
    vector<string> answer;
    if(n == 0) {
        return answer;
    }
    if(n < 10) {
        answer.push_back(ones[n]);
    }
    else if(n < 20) {
        answer.push_back(teens[n % 10]);
    }
    else {
        answer.push_back(tens[n / 10]);
        if(n % 10 != 0) {
            answer.push_back(ones[n % 10]);
        }
    }
    return answer;
}

// Convert Hunderds to Words
vector<string> convertHundreds(LL n) {
    vector<string> answer;
    if(n == 0) {
        return answer;
    }
    if(n / 100 != 0) {
        answer.push_back(ones[n / 100]);
        answer.push_back(hundred);
    }
    for(string s : convertTens(n % 100)) {
        answer.push_back(s);
    }
    return answer;
}

int main() {
    sll(t);
    rep(_, 0, t) {
        sll(n);
        LL t = (n / (1000000000000));
        LL b = (n % (1000000000000)) / (1000000000);
        LL m = (n % (1000000000)) / (1000000);
        LL th = (n % (1000000)) / (1000);
        LL h = (n % (1000));
        vector<string> answer;
        if(t != 0) {
            answer.push_back(ones[t]);
            answer.push_back(trillion);
        }
        if(b != 0) {
            for(string s : convertHundreds(b)) {
                answer.push_back(s);
            }
            answer.push_back(billion);
        }
        if(m != 0) {
            for(string s : convertHundreds(m)) {
                answer.push_back(s);
            }
            answer.push_back(million);
        }
        if(th != 0) {
            for(string s : convertHundreds(th)) {
                answer.push_back(s);
            }
            answer.push_back(thousand);
        }
        if(h != 0) {
            for(string s : convertHundreds(h)) {
                answer.push_back(s);
            }
        }

        for(string s : answer) {
            cout << s << " ";
        } nl;
    }
}
